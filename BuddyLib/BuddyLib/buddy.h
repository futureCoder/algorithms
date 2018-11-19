#ifndef _TCLC_MEMORY_BUDDY_H
#define _TCLC_MEMORY_BUDDY_H

#include "types.h"
#include "config.h"
#include "memory.h"

#if ((TCLC_MEMORY_ENABLE) && (TCLC_MEMORY_BUDDY_ENABLE))

#define MEM_BUDDY_PAGE_TAGS  ((TCLC_MEMORY_BUDDY_PAGES + 31u) >> 5u)
#define MEM_BUDDY_NODE_TAGS (TCLC_MEMORY_BUDDY_PAGES * 2u - 1u)

typedef struct MemBuddyDef {
	UINT32	Property;						/*	内存池属性				*/
	char*	PageAddr;						/*	被管理的内存的起始地址	*/
	UINT32	PageSize;						/*	内存页大小				*/
	UINT32	PageNum;						/*	内存页数目				*/
	UINT32	PageAvail;						/*	可用内存页数目			*/
	UINT32	PageTags[MEM_BUDDY_PAGE_TAGS];	/*	内存页是否可用标记		*/
	UINT32	NodeNum;						/*	树结点总数				*/
	UCHAR	NodeTags[MEM_BUDDY_NODE_TAGS];	/*	每个结点管理的页数		*/
} TMemBuddy;

extern TState Buddy_Create(TMemBuddy* pBuddy, char* pAddr, UINT32 pages, UINT32 pagesize, TError* pError);
extern TState Buddy_Delete(TMemBuddy* pBuddy, TError* pError);
extern TState Buddy_MemMalloc(TMemBuddy* pBuddy, UINT32 size, void** pAddr, TError* pError);
extern TState Buddy_MemFree(TMemBuddy* pBuddy, void* pAddr, TError* pError);

#endif

#endif /* _TCLC_MEMORY_BUDDY_H  */
