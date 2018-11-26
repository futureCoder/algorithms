
namespace Solution
{
	//////////////////////////////////////////////////////////////////////////
	//双向链表结点//
	//////////////////////////////////////////////////////////////////////////
	template <typename T>
	class DLListNode
	{
	public:
		T GetVal()
		{
			return m_Val;
		}
		DLListNode(T val)
		{
			m_Val = val;
			m_pPrev = nullptr;
			m_pNext = nullptr;
		}
		T m_Val;
		DLListNode<T>* m_pPrev;
		DLListNode<T>* m_pNext;
	};
	//////////////////////////////////////////////////////////////////////////
	//双向链表容器//
	//////////////////////////////////////////////////////////////////////////
	template <typename T>
	class DoubleLinkedList 
	{
	public:
		typedef T value_type;
		/** Initialize your data structure here. */
		DoubleLinkedList();
		virtual ~DoubleLinkedList();
		/** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
		T get(int index);

		/** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
		DLListNode<T>* addAtHead(T val);

		/** Append a node of value val to the last element of the linked list. */
		DLListNode<T>* addAtTail(T val);

		/** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
		DLListNode<T>* addAtIndex(int index, T val);

		/** Delete the index-th node in the linked list, if the index is valid. */
		void deleteAtIndex(int index);

		DLListNode<T>* popAtIndex(int index);
		DLListNode<T>* pop_back();
		DLListNode<T>* _GetDLNode(T val);
		DLListNode<T>* _GetNodeAtIndex(int index);
		int size() { return m_nCount; }
	private:
		DLListNode<T>* m_pHead;
		int m_nCount;
	};
}