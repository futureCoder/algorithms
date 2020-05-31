#ifndef _LRU_CACHE_H_
#define _LRU_CACHE_H_

#include "leetcode.h"
namespace Arch
{
    class LRUCache {
    public:
        template<typename T>
        class ListNode {
        public:
            ListNode(T val)
                : m_Data(val)
                , m_pNext(nullptr)
            {}
            ListNode()
                : ListNode(0)
            {}
            T m_Data;
            ListNode* m_pNext;
        };
        using PII = pair<int, int>;
        using LNPII = ListNode<PII>;
        LRUCache(int capacity)
            : m_nSize(0)
            , m_nCapacity(capacity)
            , m_pHead(nullptr)
        {
        }

        int get(int key) {
            if (!hasKey(key))
                return -1;
            toHead(key);
            auto iter = m_vMap.find(key);
            return (*(iter->second))->m_Data.second;
        }

        void put(int key, int value) {
            if (hasKey(key))
            {
                auto iter = m_vMap.find(key);
                (*(iter->second))->m_Data.second = value;
                toHead(key);
                return;
            }
            if (IsFull())
            {
                del();
            }
            add(key, value);
        }
    private:
        bool empty() const { return m_nSize == 0; }
        bool IsFull() const { return m_nSize == m_nCapacity; }
        bool hasKey(int key) const { return m_vMap.find(key) != m_vMap.end(); }
        void toHead(int key) {
            if (!hasKey(key))
                return;
            auto iter = m_vMap.find(key);
            LNPII** ppNode = iter->second;
            LNPII* pNode = *ppNode;
            *ppNode = pNode->m_pNext;
            if (*ppNode)
                update((*ppNode)->m_Data.first, ppNode);
            pNode->m_pNext = m_pHead;
            m_pHead = pNode;
            if (pNode->m_pNext)
                update(pNode->m_pNext->m_Data.first, &(pNode->m_pNext));
            update(pNode->m_Data.first, &m_pHead);
        }
        void add(int key, int value) {
            if (IsFull())
                return;
            LNPII* pNode = new LNPII({ key, value });
            pNode->m_pNext = m_pHead;
            m_pHead = pNode;
            if (pNode->m_pNext)
                update(pNode->m_pNext->m_Data.first, &(pNode->m_pNext));
            update(pNode->m_Data.first, &m_pHead);
            ++m_nSize;
        }
        void del(int key) {
            if (!hasKey(key))
                return;
            auto iter = m_vMap.find(key);

            LNPII** ppNode = iter->second;
            LNPII* pNode = *ppNode;
            *ppNode = pNode->m_pNext;

            delete pNode;
            m_vMap.erase(key);

            --m_nSize;
        }
        void del() {
            if (!IsFull())
                return;
            LNPII* pNode = m_pHead;
            while (pNode && pNode->m_pNext)
                pNode = pNode->m_pNext;
            if (pNode)
                del(pNode->m_Data.first);
        }
        void update(int key, LNPII** ppNode) {
            m_vMap[key] = ppNode;
        }
    private:
        int m_nSize{ 0 };
        int m_nCapacity{ 0 };
        LNPII* m_pHead;
        unordered_map<int, LNPII**> m_vMap;
    };

    void LRUCache_get(LRUCache& cache, int key) {
        cout << cache.get(key) << endl;
    }
    void LRUCache_put(LRUCache& cache, int key, int value) {
        cache.put(key, value);
    }

    void LRUCache_unitTest()
    {
        LRUCache cache(2);
        LRUCache_get(cache, 2);
        LRUCache_put(cache, 2, 6);
        LRUCache_get(cache, 1);
        LRUCache_put(cache, 1, 5);
        LRUCache_put(cache, 1, 2);
        LRUCache_get(cache, 1);
        LRUCache_get(cache, 2);
        
    }

}


#endif // !_LRU_CACHE_H_
