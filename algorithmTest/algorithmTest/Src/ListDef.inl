#include "leetcode.h"
namespace Solution
{
	template <typename T>
	DoubleLinkedList<T>::DoubleLinkedList() {
		m_nCount = 0;
		m_pHead = nullptr;
	}
	template <typename T>
	DoubleLinkedList<T>::~DoubleLinkedList()
	{
		while (m_nCount >= 0)
		{
			DLListNode* pNode = popAtIndex(0);
			delete pNode;
		}
	}
	template <typename T>
	T DoubleLinkedList<T>::get(int index)
	{
		DLListNode* pNode = _GetNodeAtIndex(index);
		if (nullptr == pNode)
			return -1;
		return pNode->m_nVal;
	}
	template <typename T>
	DLListNode<T>* DoubleLinkedList<T>::addAtHead(T val) {
		return addAtIndex(0, val);
	}

	template <typename T>
	DLListNode<T>* DoubleLinkedList<T>::addAtTail(T val) {
		return addAtIndex(m_nCount, val);
	}
	template <typename T>
	DLListNode<T>* DoubleLinkedList<T>::addAtIndex(int index, T val) {
		DLListNode* pNode = _GetNodeAtIndex(index == m_nCount ? 0 : index);
		if (nullptr == pNode)
		{
			if (0 != m_nCount || 0 != index)
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
		if (0 == index)
			m_pHead = pNewNode;
		++m_nCount;
	}
	template <typename T>
	void DoubleLinkedList<T>::deleteAtIndex(int index) {
		DLListNode* pNode = popAtIndex(index);
		delete pNode;
	}
	template <typename T>
	DLListNode<T>* DoubleLinkedList<T>::popAtIndex(int index)
	{
		DLListNode* pNode = _GetNodeAtIndex(index);
		if (nullptr == pNode)
			return;
		pNode->m_pPrev->m_pNext = pNode->m_pNext;
		pNode->m_pNext->m_pPrev = pNode->m_pPrev;
		if (0 == index)
		{
			m_pHead = pNode->m_pNext;
		}
		--m_nCount;
		if (0 == m_nCount)
		{
			m_pHead = nullptr;
		}
		pNode->m_pPrev = nullptr;
		pNode->m_pNext = nullptr;
		return pNode;
	}
	template<typename T>
	DLListNode<T>* DoubleLinkedList<T>::pop_back()
	{
		return popAtIndex(m_nCount - 1);
	}
    template<typename T>
    DLListNode<T>* DoubleLinkedList<T>::pop_front()
    {
        return popAtIndex(0);
    }
	template <typename T>
	DLListNode<T>* DoubleLinkedList<T>::_GetDLNode(T val)
	{
		DLListNode* ret = new DLListNode(val);
		return ret;
	}
	template <typename T>
	DLListNode<T>* DoubleLinkedList<T>::_GetNodeAtIndex(int index)
	{
		if (index < 0 || index >= m_nCount)
			return nullptr;
		DLListNode* pNode = m_pHead;
		while (index > 0)
		{
			pNode = pNode->m_pNext;
			--index;
		}
		return pNode;
	}
}