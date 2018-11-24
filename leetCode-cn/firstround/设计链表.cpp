class MyLinkedList {
public:
    /** Initialize your data structure here. */
    MyLinkedList() {
        m_nCount = 0;
        m_pHead = nullptr;
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        if(0 <= index && index < m_nCount)
        {
            DLListNode* node = m_pHead;

        }
        return -1;
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        DLListNode* node = _addAtTail;
        m_pHead = node;
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        _addAtTail(val);
    }

    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        DLListNode* pNode = _GetNodeAtIndex(index);
        if(nullptr == pNode)
            return;
        DLListNode* pNewNode = _GetDLNode(val);
        if(nullptr == pNewNode)
            return;
        pNewNode->m_pPrev = pNode->m_pPrev;
        pNewNode->m_pNext = pNode;
        pNode->m_pPrev = pNewNode;
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        DLListNode* pNode = _GetNodeAtIndex(index);
        if(nullptr == pNode)
            return;
        pNode->m_pPrev->m_pNext = pNode->m_pNext;
        pNode->m_pNext->m_pPrev = pNode->m_pPrev;
        Delete pNode;
    }

    DLListNode* _GetDLNode(int val)
    {
        DLListNode* ret = new DLListNode(val);
        return ret;
    }
    DLListNode* _AddAtTail(int val)
    {
        DLListNode* node = _GetDLNode(val);
        if(nullptr == node)
            return;
        if(nullptr == m_pHead)
        {
            node->m_pNext = node;
            node->m_pPrev = node;
            m_pHead = node;
            return node;
        }
        node->m_pNext = m_pHead;
        node->m_pPrev = m_pHead->m_pPrev;
        m_pHead->m_pPrev->m_pNext = node;
        m_pHead->m_pPrev = node;
        ++m_nCount;
        return node;
    }
    DLListNode* _GetNodeAtIndex(int index)
    {
        if(0 <= index && index <= m_nCount)
        {
            index %= m_nCount;
            DLListNode* pNode = m_pHead;
            while(index > 0)
            {
                pNode = pNode->m_pNext);
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
            m_nVal = v;
            m_pPrev = nullptr;
            m_pNext = nullptr;
        }
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList obj = new MyLinkedList();
 * int param_1 = obj.get(index);
 * obj.addAtHead(val);
 * obj.addAtTail(val);
 * obj.addAtIndex(index,val);
 * obj.deleteAtIndex(index);
 */