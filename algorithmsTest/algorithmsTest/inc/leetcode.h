#ifndef _LEETCODE__H_
#include "stdafx.h"
namespace Solution {
    class MyLinkedList {
    public:
        class DLListNode;
        /** Initialize your data structure here. */
        MyLinkedList() {
            m_nCount = 0;
            m_pHead = nullptr;
        }

        /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
        int get(int index) {
            DLListNode* pNode = _GetNodeAtIndex(index);
            if (nullptr == pNode)
                return -1;
            return pNode->m_nVal;
        }

        /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
        void addAtHead(int val) {
            addAtIndex(0, val);
        }

        /** Append a node of value val to the last element of the linked list. */
        void addAtTail(int val) {
            addAtIndex(m_nCount, val);
        }

        /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
        void addAtIndex(int index, int val) {
            DLListNode* pNode = _GetNodeAtIndex(index);
            if (nullptr == pNode)
            {
                if (0 != m_nCount)
                    return;
                DLListNode* pNewNode = _GetDLNode(val);
                pNewNode->m_pPrev = pNewNode;
                pNewNode->m_pNext = pNewNode;
                m_pHead = pNewNode;
                ++m_nCount;
                return;
            }
            DLListNode* pNewNode = _GetDLNode(val);
            if (nullptr == pNewNode)
                return;
            pNewNode->m_pPrev = pNode->m_pPrev;
            pNewNode->m_pNext = pNode;
            pNode->m_pPrev->m_pNext = pNewNode;
            pNode->m_pPrev = pNewNode;
            ++m_nCount;
            if (0 == index)
                m_pHead = pNewNode;
        }

        /** Delete the index-th node in the linked list, if the index is valid. */
        void deleteAtIndex(int index) {
            DLListNode* pNode = _GetNodeAtIndex(index);
            if (nullptr == pNode)
                return;
            pNode->m_pPrev->m_pNext = pNode->m_pNext;
            pNode->m_pNext->m_pPrev = pNode->m_pPrev;
            --m_nCount;
            delete pNode;
            if (0 == m_nCount)
                m_pHead = nullptr;
        }

        DLListNode* _GetDLNode(int val)
        {
            DLListNode* ret = new DLListNode(val);
            return ret;
        }
        DLListNode* _GetNodeAtIndex(int index)
        {
            if (0 <= index && index <= m_nCount)
            {
                if (0 != m_nCount)
                    index %= m_nCount;
                DLListNode* pNode = m_pHead;
                while (index > 0)
                {
                    pNode = pNode->m_pNext;
                    --index;
                }
                return pNode;
            }
            return nullptr;
        }
        DLListNode* m_pHead;
        int m_nCount;
        class DLListNode
        {
        public:
            int m_nVal;
            DLListNode* m_pPrev;
            DLListNode* m_pNext;
            DLListNode(int val)
            {
                m_nVal = val;
                m_pPrev = nullptr;
                m_pNext = nullptr;
            }
        };
    };
}

#endif // !_LEETCODE__H_

