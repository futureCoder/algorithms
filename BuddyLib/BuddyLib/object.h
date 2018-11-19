/*************************************************************************************************
*                                     Trochili RTOS Kernel                                      *
*                                  Copyright(C) 2016 LIUXUMING                                  *
*                                       www.trochili.com                                        *
*************************************************************************************************/
#ifndef _TCL_OBJECT_H
#define _TCL_OBJECT_H
#include "types.h"
#include "config.h"

enum ObjectTypeDef
{
	eThread = 0,
	eTimer,
	eSemaphore,
	eMutex,
	eMailbox,
	eMessage,
	eFlag
};
typedef enum ObjectTypeDef TObjectType;

struct LinkNodeDef
{
	struct LinkNodeDef*  Prev;
	struct LinkNodeDef*  Next;
	struct LinkNodeDef** Handle;
	void*    Owner;
	UINT32* Data;
};
typedef struct LinkNodeDef TLinkNode;

typedef enum LinkPosDef
{
	eLinkPosHead,
	eLinkPosTail
} TLinkPos;


struct ObjectDef
{
	UINT32       ID;                                   
	TObjectType   Type;                              
	char         Name[TCL_OBJ_NAME_LEN];               
	void*         Owner;                                
	TLinkNode     LinkNode;                             
};
typedef struct ObjectDef TObject;

extern void uObjQueueAddFifoNode(TLinkNode** pHandle2, TLinkNode* pNode, TLinkPos pos);
extern void uObjQueueAddPriorityNode(TLinkNode** pHandle2, TLinkNode* pNode);
extern void uObjQueueRemoveNode(TLinkNode** pHandle2, TLinkNode* pNode);
extern void uObjListAddNode(TLinkNode** pHandle2, TLinkNode* pNode, TLinkPos pos);
extern void uObjListRemoveNode(TLinkNode** pHandle2, TLinkNode* pNode);
extern void uObjListAddPriorityNode(TLinkNode** pHandle2, TLinkNode* pNode);
extern void uObjListAddDiffNode(TLinkNode** pHandle2, TLinkNode* pNode);
extern void uObjListRemoveDiffNode(TLinkNode** pHandle2, TLinkNode* pNode);

#endif /* _TCL_OBJECT_H */

