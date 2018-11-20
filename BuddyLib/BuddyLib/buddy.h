#ifndef _TCLC_MEMORY_BUDDY_H
#define _TCLC_MEMORY_BUDDY_H

#include "types.h"
#include "config.h"
#include "memory.h"

#if ((TCLC_MEMORY_ENABLE) && (TCLC_MEMORY_BUDDY_ENABLE))

#define MEM_BUDDY_PAGE_TAGS  ((TCLC_MEMORY_BUDDY_PAGES + 31u) >> 5u)
#define MEM_BUDDY_NODE_TAGS (TCLC_MEMORY_BUDDY_PAGES * 2u - 1u)

typedef struct MemBuddyDef {
	UINT32	Property;						/*	�ڴ������				*/
	char*	PageAddr;						/*	��������ڴ����ʼ��ַ	*/
	UINT32	PageSize;						/*	�ڴ�ҳ��С				*/
	UINT32	PageNum;						/*	�ڴ�ҳ��Ŀ				*/
	UINT32	PageAvail;						/*	�����ڴ�ҳ��Ŀ			*/
	UINT32	PageTags[MEM_BUDDY_PAGE_TAGS];	/*	�ڴ�ҳ�Ƿ���ñ��		*/
	UINT32	NodeNum;						/*	���������				*/
	UCHAR	NodeTags[MEM_BUDDY_NODE_TAGS];	/*	ÿ���������ҳ��		*/
} TMemBuddy;

extern TState Buddy_Create(TMemBuddy* pBuddy, char* pAddr, UINT32 pages, UINT32 pagesize, TError* pError);
extern TState Buddy_Delete(TMemBuddy* pBuddy, TError* pError);
extern TState Buddy_MemMalloc(TMemBuddy* pBuddy, UINT32 size, void** pAddr, TError* pError);
extern TState Buddy_MemFree(TMemBuddy* pBuddy, void* pAddr, TError* pError);

#endif

#endif /* _TCLC_MEMORY_BUDDY_H  */
