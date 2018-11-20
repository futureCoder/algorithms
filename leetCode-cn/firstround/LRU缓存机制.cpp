static const auto io_sync_off = []()
{
    // turn off sync
    std::ios::sync_with_stdio(false);
    // untie in/out streams
    std::cin.tie(nullptr);
    return nullptr;
}();
class LRUCache {
public:
    LRUCache(int capacity) {
        m_nCurr = 0;
        m_pHead = nullptr;
        m_nMax = capacity;
        m_vHash.resize(capacity);
    }
    
    int get(int key) {
        DoubleLinkedListNode** node = _get(key);
        return _VisitNode(*node);
    }
    
    void put(int key, int value) {
        HashLinkedListNode** hashNode = _get(key);
        if(nullptr != *hashNode)    //已存在
        {
            (*hashNode)->pKVNode->value = value;    //更新现有key-value
            _VisitNode((*hashNode)->pKVNode);       //调整dlList
            return;
        }

        DoubleLinkedListNode* dlNode = nullptr;
        if(m_nCurr < m_nMax)
        {
            dlNode = new DoubleLinkedListNode(value);
            if(nullptr == m_pHead)
            {
                dlNode->next = dlNode;
                dlNode->prev = dlNode;
            }
            else
            {
                dlNode->next = m_pHead;
                dlNode->prev = m_pHead->prev;
            }
            m_pHead = dlNode;
        }
        else
        {
            dlNode = DetachTailNode();
            dlNode->next = m_pHead;
            dlNode->prev = m_pHead->prev;
            m_pHead = dlNode;
        }
        hashNode = new HashLinkedListNode(dlNode);
        
    }

    HashLinkedListNode* _GetHashLinkedListNode()
    {
        if(m_nCurr == m_nMax)
        {
            return _RemoveLRUNodeInHash();
        }
        DoubleLinkedListNode* dlNode = new do
    }

    HashLinkedListNode* _RemoveLRUNodeInHash()
    {
        DoubleLinkedListNode* dlNode = _RemoveLRUNodeInDLList();
        if(nullptr == dlNode)
            return nullptr;
        HashLinkedListNode** root = _get(dlNode->key);
        HashLinkedListNode* hashNode = *root;
        if(hashNode)
        {
            *root = hashNode->next;
            hashNode->next = nullptr;
        }
        return hashNode;
    }

    HashLinkedListNode** _get(int key)
    {
        int pos = _HashFun(key);
        HashLinkedListNode** root = &m_vHash[pos];
        while(*root)
        {
            if(nullptr != (*root)->pKVNode && (*root)->pKVNode->key == key)
                break;
            root = &((*root)->next);
        }
        return root;
    }

    int _HashFun(int key)
    {
        return (key % m_nMax);
    }

    int _VisitNode(DoubleLinkedListNode* node)
    {
        if(node == m_pHead)
            return node->val;
        //从链表中剥离node
        node->next->prev = node->prev;
        node->prev->next = node->next;
        //将node插到表头
        node->prev = m_pHead->prev;
        node->next = m_pHead;
        m_pHead = node;
        return m_pHead->val;
    }

    DoubleLinkedListNode* _RemoveLRUNodeInDLList()
    {
        if(m_pHead == m_pHead->prev)
            return m_pHead;
        DoubleLinkedListNode* node = m_pHead->prev;
        node->next->prev = node->prev;
        node->prev->next = node->next;
        node->prev = nullptr;
        node->next = nullptr;
        return node;
    }

    class HashLinkedListNode
    {
    public:
        DoubleLinkedListNode* pKVNode;
        HashLinkedListNode* next;
        HashLinkedListNode(DoubleLinkedListNode* node)
        {
            pKVNode = node;
            next = nullptr;
        }
    }

    class DoubleLinkedListNode
    {
    public:
        int key;
        int value;
        DoubleLinkedListNode* prev;
        DoubleLinkedListNode* next;
        DoubleLinkedListNode(int val)
        {
            value = val;
            prev = nullptr;
            next = nullptr;
        }
        void SetNext(const DoubleLinkedListNode *node)
        {
            next = node;
        }
        void SetPrev(const DoubleLinkedListNode *node)
        {
            prev = node
        }
    }DoubleLinkedListNode;

    private:
    std::vector<HashLinkedListNode*> m_vHash;  //hash
    DoubleLinkedListNode* m_pHead;              //双向链表头结点
    int m_nMax;                     //LRU capacity
    int m_nCurr;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */