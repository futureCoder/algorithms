//#include "stdafx.h"
//namespace Solution
//{
//	static const auto io_sync_off = []()
//	{
//		// turn off sync
//		std::ios::sync_with_stdio(false);
//		// untie in/out streams
//		std::cin.tie(nullptr);
//		return nullptr;
//	}();
//	class LRUCache {
//	public:
//		class HashLinkedListNode;
//		LRUCache(int capacity) {
//			m_nCurr = 0;
//			m_pList = new DoubleLinkedList();
//			m_nMax = capacity;
//			m_vHash.resize(capacity);
//		}
//
//		int get(int key) {
//			HashLinkedListNode** node = _get(key);
//			if (!(*node))
//				return -1;
//			return _VisitNode((*node)->pValueNode);
//		}
//
//		void put(int key, int value) {
//			HashLinkedListNode** hashNode = _get(key);
//			if (nullptr != *hashNode)    //已存在
//			{
//				(*hashNode)->pValueNode->value = value;    //更新现有key-value
//				_VisitNode((*hashNode)->pValueNode);       //调整dlList
//				return;
//			}
//			PutNewData(key, value);
//		}
//
//		void PutNewData(int key, int value)
//		{
//			HashLinkedListNode* hashNode = _GetHashLinkedListNode(key, value);
//			int pos = _HashFun(key);
//			hashNode->next = m_vHash[pos];
//			m_vHash[pos] = hashNode;
//		}
//
//		HashLinkedListNode* _GetHashLinkedListNode(int key, int value)
//		{
//			DLListNode* dlNode = _GetDLNode(key, value);
//			HashLinkedListNode* hashNode = _RemoveLRUNodeInHash(dlNode);
//			if (nullptr == hashNode)
//			{
//				hashNode = new HashLinkedListNode(dlNode);
//			}
//			return hashNode;
//		}
//
//		HashLinkedListNode* _RemoveLRUNodeInHash(DLListNode* dlNode)
//		{
//			if (nullptr == dlNode)
//				return nullptr;
//			HashLinkedListNode** root = _get(dlNode->key);
//			HashLinkedListNode* hashNode = *root;
//			if (hashNode)
//			{
//				*root = hashNode->next;
//				hashNode->next = nullptr;
//			}
//			return hashNode;
//		}
//
//		HashLinkedListNode** _get(int key)
//		{
//			int pos = _HashFun(key);
//			HashLinkedListNode** root = &m_vHash[pos];
//			while (*root)
//			{
//				if (nullptr != (*root)->pValueNode && (*root)->pKVNode->key == key)
//					break;
//				root = &((*root)->next);
//			}
//			return root;
//		}
//
//		int _HashFun(int key)
//		{
//			return (key % m_nMax);
//		}
//
//		int _VisitNode(DLListNode<std::pair<int, int>>* node)
//		{
//			if (nullptr == node)
//				return -1;
//			if (node == m_pHead)
//				return node->value;
//			//从链表中剥离node
//			node->next->prev = node->prev;
//			node->prev->next = node->next;
//			//将node插到表头
//			node->prev = m_pHead->prev;
//			node->next = m_pHead;
//			m_pHead = node;
//			return m_pHead->value;
//		}
//
//		DLListNode<std::pair<int, int>>* _RemoveLRUNodeInDLList()
//		{
//			return m_pList->pop_back();
//		}
//
//		class HashLinkedListNode
//		{
//		public:
//			DLListNode<std::pair<int, int>>* pValueNode;
//			HashLinkedListNode* next;
//			HashLinkedListNode(DLListNode<std::pair<int, int>>* node)
//			{
//				pValueNode = node;
//				next = nullptr;
//			}
//		};
//
//	private:
//		std::vector<HashLinkedListNode*> m_vHash;  //hash
//		DoubleLinkedList<std::pair<int, int>>* m_pList;
//		int m_nMax;                     //LRU capacity
//		int m_nCurr;
//	};
//
//	/**
//	* Your LRUCache object will be instantiated and called as such:
//	* LRUCache obj = new LRUCache(capacity);
//	* int param_1 = obj.get(key);
//	* obj.put(key,value);
//	*/
//}
//
