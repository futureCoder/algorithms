/*************************************************************************************************
*                                     Trochili RTOS Kernel                                      *
*                                  Copyright(C) 2016 LIUXUMING                                  *
*                                       www.trochili.com                                        *
*************************************************************************************************/
#include <string.h>

#include "config.h"
#include "types.h"
#include "buddy.h"

#if ((TCLC_MEMORY_ENABLE) && (TCLC_MEMORY_BUDDY_ENABLE))

/* BUDDY���Ա�Ƕ��� */
#define BUDDY_PROP_NONE           (0x0)                  /* BUDDY�����Ա��                     */
#define BUDDY_PROP_READY          (0x1<<0U)              /* BUDDY�������                       */

#define PAGES_AVAIL (0x1<<7u)

#define PARENT_NODE(x) (((x) - 1u) / 2u)
#define LEFT_NODE(x) ((x) * 2u + 1u)
#define RIGHT_NODE(x) ((x) * 2u + 2u)

/* ����x������������Ҳ�С������2������ */
static UINT32 clp2(UINT32 x)
{
	x = x - 1U;
	x = x | (x >> 1U);
	x = x | (x >> 2U);
	x = x | (x >> 4U);
	x = x | (x >> 8U);
	x = x | (x >> 16U);
	return (x + 1U);
}

/* ����x������������Ҳ���������2������ */
static UINT32 flp2(UINT32 x) {
	x = x | (x >> 1U);
	x = x | (x >> 2U);
	x = x | (x >> 4U);
	x = x | (x >> 8U);
	x = x | (x >> 16U);
	return (x - (x >> 1U));
}

/* ����x��2Ϊ�׵Ķ��� */
static UINT32 log2(UINT32 x)
{
	UINT32 i = 0;
	while (!(x & 0x1)) {
		i++;
		x = x >> 1;
	}

	return i;
}

/* ����2��x���� */
static UINT32 power2(UINT32 x)
{
	UINT32 i = 1;
	while (x)
	{
		i = i << 1;
		x--;
	}

	return i;
}


/*************************************************************************************************
*  ���ܣ�����ÿ���������ڵ������ڴ�ҳ��                                                       *
*  ������(1) pBuddy  ���ϵͳ��������ַ                                                         *
*  ����: ��                                                                                     *
*  ˵����                                                                                       *
*************************************************************************************************/
static void BuildPageTree(TMemBuddy* pBuddy) {
	UINT32 node;
	UINT32 logn;
	UINT32 x;
	UINT32 y;
	/* �������Ľڵ����� */
	pBuddy->NodeNum = pBuddy->PageNum * 2u - 1u;
	/* ����ÿ���ڵ�����ҳ��(������2Ϊ�׵Ķ�������ʾ) */
	logn = log2(pBuddy->PageNum) & 0x3f;
	node = 0U;
	for (y = 0; y <= logn; y++) {
		x = (pBuddy->PageNum >> (logn - y));
		while (x--) {
			pBuddy->NodeTags[node] = ((logn - y) | PAGES_AVAIL);
			node++;
		}
	}
}


static int GetAvailPages(TMemBuddy* pBuddy) {
	UCHAR tag;
	tag = pBuddy->NodeTags[0];
	if (tag & PAGES_AVAIL) {
		return power2(tag & 0x3f);
	}
	return 0;
}

/*************************************************************************************************
*  ���ܣ��ӻ��������з���һ����Ŀ��ҳ                                                         *
*  ������(1) pBuddy    ���ϵͳ�����������ַ                                                   *
*        (2) pages     ��Ҫ������ڴ�ҳ��                                                       *
*        (3) index     ����õ����ڴ�ҳ��                                                       *
*  ����: (1) ���䵽��ҳ��ı��                                                                 *
*  ˵����                                                                                       *
*************************************************************************************************/
static UINT32 MallocPages(TMemBuddy* pBuddy, UINT32 pages) {
	UINT32 index;
	UINT32 lvl;
	UINT32 node;
	UCHAR tag;
	UCHAR logn;
	UCHAR ltag;
	UCHAR rtag;
	UCHAR llogn;
	UCHAR rlogn;

	/* �����pages��Ӧ����2Ϊ�׵Ķ��� */
	logn = log2(pages);
	/* ������Ҫ������(��root����)���� */
	lvl = log2(pBuddy->PageNum) - logn;
	/* �Ӹ��ڵ㿪ʼ����lvl�Σ��ҵ��ɹ�����Ľڵ� */
	node = 0U;
	while (lvl--) {
		tag = (pBuddy->NodeTags[LEFT_NODE(node)]);
		if ((tag & PAGES_AVAIL) && ((tag & 0x3f) >= logn)) {
			node = LEFT_NODE(node);
		}
		else {
			node = RIGHT_NODE(node);
		}
	}

	/* ȡ��������ýڵ���ڴ�ҳ */
	pBuddy->NodeTags[node] = 0U;

	/* ͨ���ڵ��ż����ڴ�ҳ��� */
	index = (node + 1u) * pages - pBuddy->PageNum;
	/* ���ݵ��������ڵ�·���ϵ����нڵ�Ŀɷ����ڴ�ҳ��(ע����·���ϵ�ȫ���ڵ�) */
	while (node) {
		node = PARENT_NODE(node);
		ltag = pBuddy->NodeTags[LEFT_NODE(node)];
		rtag = pBuddy->NodeTags[RIGHT_NODE(node)];
		if ((ltag & PAGES_AVAIL) && (rtag & PAGES_AVAIL)) {
			llogn = (ltag & 0x3f);
			rlogn = (rtag & 0x3f);
			tag = (llogn > rlogn) ? llogn : rlogn;
			tag |= PAGES_AVAIL;
		}
		else if (ltag & PAGES_AVAIL) {
			tag = ltag;
		}
		else if (rtag & PAGES_AVAIL) {
			tag = rtag;
		}
		else {
			tag = 0U;
		}
		pBuddy->NodeTags[node] = tag;
	}
	return index;
}


/*************************************************************************************************
*  ���ܣ��߳�ͨ��������ֹ����,��ָ�����̴߳�������������ֹ����                                  *
*  ������(1) pBuddy    ���ϵͳ�����������ַ                                                   *
*        (2) index     ���ͷŵĶ���ڴ�ҳ����ʼҳ��                                             *
*  ����: ��                                                                                     *
*  ˵����                                                                                       *
*************************************************************************************************/
static UINT32 FreePages(TMemBuddy* pBuddy, UINT32 index)
{
	UINT32 pages;
	UINT32 node;
	UCHAR tag;
	UCHAR logn;
	UINT32 lvl;

	UCHAR ltag;
	UCHAR rtag;
	UCHAR llogn;
	UCHAR rlogn;

	/* ������ڵ���2Ϊ�׵Ķ��� */
	lvl = log2(pBuddy->PageNum);

	/* ͨ���ڴ�ҳ��Ż��Ҷ�ӽڵ��� */
	node = index + pBuddy->PageNum - 1u;

	/* ͨ����Ҷ�ӽڵ����ϻ��ݲ��ҷ������ʼ�ڴ�ҳ�Ľڵ�, �ȶԴ������Ϊ������� */
	for (logn = 0; logn <= lvl; logn++) {
		/* ����ҵ�������ڴ�(n)ҳ���Ǹ��ڵ� */
		if (!(pBuddy->NodeTags[node] & PAGES_AVAIL)) {
			break;
		}
		node = PARENT_NODE(node);
	}

	/* ���ո�����ڴ�(n)ҳ,���¼��������Թ�����ڴ�ҳ�� */
	pBuddy->NodeTags[node] = ((logn & 0x3f) | PAGES_AVAIL);
	pages = power2(logn);

	/* ���Խ��н��л��ڵ�ϲ�,��Ҫһֱ������root�ڵ㡣
	����Ǹ��ڵ�����Ҫ���²��� */
	while (node)
	{
		node = PARENT_NODE(node);
		logn++;
		ltag = pBuddy->NodeTags[LEFT_NODE(node)];
		rtag = pBuddy->NodeTags[RIGHT_NODE(node)];

		if ((ltag &PAGES_AVAIL) && (rtag &PAGES_AVAIL))
		{
			llogn = (ltag & 0x3f);
			rlogn = (rtag & 0x3f);
			if (power2(llogn) + power2(rlogn) == power2(logn))
			{
				tag = ((logn & 0x3f) | PAGES_AVAIL);
			}
			else
			{
				tag = (llogn > rlogn) ? llogn : rlogn;
				tag |= PAGES_AVAIL;
			}
		}
		else if (ltag &PAGES_AVAIL)
		{
			tag = ltag;
		}
		else //if (rtag &PAGES_AVAIL)
		{
			tag = rtag;
		}
		pBuddy->NodeTags[node] = tag;
	}

	return pages;
}


/*************************************************************************************************
*  ���ܣ���ʼ������ڴ������ƽṹ                                                             *
*  ������(1) pBuddy    ���ϵͳ�������ڴ��ַ                                                   *
*        (2) pAddr     �ɹ�������ڴ��ַ                                                       *
*        (3) pagesize  �ڴ�ҳ��С                                                               *
*        (4) pages     �ɹ�������ڴ�ҳ����                                                     *
*        (5) pError    ��ϸ���ý��                                                             *
*  ����: (1) eSuccess  �����ɹ�                                                                 *
*        (2) eFailure  ����ʧ��                                                                 *
*  ˵����                                                                                       *
*************************************************************************************************/
TState Buddy_Create(TMemBuddy* pBuddy, char* pAddr, UINT32 pages, UINT32 pagesize, TError* pError) {
	TState state = eFailure;
	TError error = MEM_ERR_FAULT;
	UINT32 index;
	/*=========SEMTAKE=========*/
	if (!(pBuddy->Property & BUDDY_PROP_READY))	{
		/* ����pages������������Ҳ���������2������ */
		pages = flp2(pages);
		if (pages) {
			pBuddy->Property = BUDDY_PROP_READY;
			pBuddy->PageAddr = pAddr;
			pBuddy->PageSize = pagesize;
			pBuddy->PageNum = pages;
			pBuddy->PageAvail = pages;

			/* ���������ڴ涼���ڿɷ���״̬ */
			for (index = 0; index < MEM_BUDDY_PAGE_TAGS; index++) {
				/*��λ���÷���״̬ 1���� 0������*/
				pBuddy->PageTags[index] = ~0U;
			}
			/* �������������ƽṹ */
			BuildPageTree(pBuddy);

			error = MEM_ERR_NONE;
			state = eSuccess;
		}
	}
	/*=========SEMGIVE=========*/
	*pError = error;
	return state;
}


/*************************************************************************************************
*  ���ܣ����ٻ���ڴ������ƽṹ                                                               *
*  ������(1) pBuddy     ���ϵͳ�������ڴ��ַ                                                  *
*        (2) pError     ��ϸ���ý��                                                            *
*  ����: (1) eSuccess   �����ɹ�                                                                *
*        (2) eFailure   ����ʧ��                                                                *
*  ˵����                                                                                       *
*************************************************************************************************/
TState Buddy_Delete(TMemBuddy* pBuddy, TError* pError)
{
	TReg32 imask;
	TState state = eFailure;
	TError error = MEM_ERR_UNREADY;

	/*=========SEMTAKE=========*/
	if (pBuddy->Property & MEM_PROP_READY)
	{
		memset(pBuddy->PageAddr, 0U, pBuddy->PageSize * pBuddy->PageNum);
		memset(pBuddy, 0U, sizeof(TMemBuddy));
		error = MEM_ERR_NONE;
		state = eSuccess;
	}
	/*=========SEMGIVE=========*/

	*pError = error;
	return state;
}


/*************************************************************************************************
*  ���ܣ��ӻ��ϵͳ�������ڴ�                                                                   *
*  ������(1) pBuddy    ���ϵͳ�����������ַ                                                   *
*        (2) len       ��Ҫ������ڴ泤��                                                       *
*        (3) pAddr2    ����õ����ڴ��ַָ��                                                   *
*        (4) pError    ��ϸ���ý��                                                             *
*  ����: (1) eSuccess  �����ɹ�                                                                 *
*        (2) eFailure  ����ʧ��                                                                 *
*  ˵����                                                                                       *
*************************************************************************************************/
TState Buddy_MemMalloc(TMemBuddy* pBuddy, UINT32 size, void** pAddr2, TError* pError) {
	TState state = eFailure;
	TError error = MEM_ERR_UNREADY;
	UINT32 pages;
	UINT32 index;
	UINT32 avail;
	UINT32 x;
	UINT32 y;
	UINT32 i;
	/*=========SEMTAKE=========*/
	if (pBuddy->Property & BUDDY_PROP_READY) {
		/* ���������ڴ泤��û�г���BUDDY�ķ�Χ */
		if (size <= (pBuddy->PageNum * pBuddy->PageSize)) {
			/* ������Ҫ��������ڴ�ҳ */
			pages = (size + pBuddy->PageSize - 1u) / (pBuddy->PageSize);
			/* ����pages������������Ҳ�С������2������ */
			pages = clp2(pages);
			avail = GetAvailPages(pBuddy);
			if (avail >= pages) {
				/* ��÷�����ڴ�ҳ��� */
				index = MallocPages(pBuddy, pages);
				/* ��Ǹò����ڴ�ҳ�Ѿ������� */
				for (i = 0; i < pages; i++) {
					y = ((index + i) >> 5);
					x = ((index + i) & 0x1f);
					pBuddy->PageTags[y] &= ~(0x1 << x);
				}
				pBuddy->PageAvail -= pages;
				/* ͨ���ڴ�ҳ��Ż���ڴ��ַ */
				*pAddr2 = (void*)(pBuddy->PageAddr + index * pBuddy->PageSize);
				error = MEM_ERR_NONE;
				state = eSuccess;
			}
			else {
				*pAddr2 = (void*)0;
				error = MEM_ERR_NO_MEM;
			}
		}
		else {
			error = MEM_ERR_NO_MEM;
		}
	}
	/*=========SEMGIVE=========*/
	*pError = error;
	return state;
}


/*************************************************************************************************
*  ���ܣ�����ϵͳ���ͷ��ڴ�                                                                   *
*  ������(1) pBuddy    ���ϵͳ�����������ַ                                                   *
*        (2) pAddr     ���ͷŵ��ڴ��ַ                                                         *
*        (3) pError    ��ϸ���ý��                                                             *
*  ����: (1) eSuccess  �����ɹ�                                                                 *
*        (2) eFailure  ����ʧ��                                                                 *
*  ˵����                                                                                       *
*************************************************************************************************/
TState Buddy_MemFree(TMemBuddy* pBuddy, void* pAddr, TError* pError)
{
	TState state = eFailure;
	TError error = MEM_ERR_UNREADY;
	TReg32 imask;
	UINT32 index;
	UINT32 x;
	UINT32 y;
	UINT32 tag;
	UINT32 pages;
	UINT32 i;

	/*=========SEMTAKE=========*/
	if ((pBuddy->Property &BUDDY_PROP_READY)) {
		/* ��鱻�ͷŵĵ�ַ�Ƿ��ڻ��ϵͳ������ڴ淶Χ�� */
		if (((char*)pAddr >= (char*)(pBuddy->PageAddr)) &&
			((char*)pAddr < ((char*)(pBuddy->PageAddr) + pBuddy->PageSize* pBuddy->PageNum))) {
			/* ͨ���ڴ��ַ������ʼҳ��� */
			index = ((char*)pAddr - (char*)(pBuddy->PageAddr)) / pBuddy->PageSize;
			/* ����ڴ�ҳ�����ǣ������ٴ��ͷ��Ѿ��ͷŹ����ڴ�ҳ��ַ */
			y = (index >> 5);
			x = (index & 0x1f);
			tag = pBuddy->PageTags[y] & (0x1 << x);
			if (tag == 0) {
				/* �ͷŸ�ҳ��ʼ���ڴ� */
				pages = FreePages(pBuddy, index);

				/* ��Ǹò����ڴ���Ա����� */
				for (i = 0; i < pages; i++) {
					y = (index + i) >> 5;
					x = (index + i) & 0x1f;
					pBuddy->PageTags[y] |= (0x1 << x);
				}

				pBuddy->PageAvail += pages;
				error = MEM_ERR_NONE;
				state = eSuccess;
			}
			else
			{
				error = MEM_ERR_DBL_FREE;
			}
		}
		else
		{
			error = MEM_ERR_BAD_ADDR;
		}
	}
	/*=========SEMGIVE=========*/

	*pError = error;
	return state;
}

#endif
