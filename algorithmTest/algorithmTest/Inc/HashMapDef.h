#ifndef _HASH_MAP_DEF__H_
#define _HASH_MAP_DEF__H_
namespace Solution
{
    //////////////////////////////////////////////////////////////////////////
    //开链法哈希表结点//
    //////////////////////////////////////////////////////////////////////////
    template <typename KeyType, typename ValueType>
    class HashLinkedListNode
    {
    public:
        typedef KeyType key_type;
        typedef ValueType value_type;
        HashLinkedListNode();
        virtual ~HashLinkedListNode();

    private:

    };

    template <typename KeyType, typename ValueType>
    class HashMap {
    public:
        typedef KeyType key_type;
        typedef ValueType value_type;
        /** Initialize your data structure here. */
        HashMap() {

        }

        /** value will always be non-negative. */
        void put(int key, int value) {

        }

        /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
        int get(int key) {

        }

        /** Removes the mapping of the specified value key if this map contains a mapping for the key */
        void remove(int key) {

        }
        std::vector<HashLinkedListNode<KeyType, value_type>> m_vHash;
        DoubleLinkedList < std::pair<key_type, value_type> m_pList;
        int m_nCurr;
        int m_nMax;
    };
}
#endif // !__LIST_DEF_H__