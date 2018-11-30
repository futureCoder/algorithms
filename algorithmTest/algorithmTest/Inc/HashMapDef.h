#ifndef _HASH_MAP_DEF__H_
#define _HASH_MAP_DEF__H_
#include "stdafx.h"
namespace Solution
{
    //////////////////////////////////////////////////////////////////////////
    //开链法哈希表结点//
    //////////////////////////////////////////////////////////////////////////
    template<typename KeyType>
    struct _HashFunc
    {
        size_t operator()(const KeyType& key, size_t capacity)
        {
            return key % capacity;
        }
    };
    template<>
    struct _HashFunc<string>
    {
        size_t operator()(const string& key, size_t capacity)
        {
            return _BKDRHash(key.c_str()) % capacity;
        }
        static size_t _BKDRHash(const char* str)
        {
            unsigned int nSeed = 131;   //13 131 13131 131313
            unsigned int nHash = 0;
            while (*str)
            {
                nHash = nHash * nSeed + *str++;
            }
            return nHash & 0x7FFFFFFF;
        }
    };


    template <typename KeyType, typename ValueType>
    class HashLinkedList
    {
    public:
        typedef KeyType key_type;
        typedef ValueType value_type;
        HashLinkedList();
        virtual ~HashLinkedList();
        DLListNode < std::pair<KeyType, ValueType>* m_pVal;
        HashLinkedList<key_type, value_type>* m_pNext;
    private:

    };

    template <typename KeyType, typename ValueType>
    class HashMap {
    public:
        static const int _num_primes = 15;
        static const int[] _prime_list[_num_primes] = {
            17, 29, 53, 97, 193,
            389, 769, 1543, 3079, 6151,
            12289, 24593, 49157, 98317, 196613
        };
        typedef KeyType key_type;
        typedef ValueType value_type;
        /** Initialize your data structure here. */
        HashMap() 
        {
            m_nCurr = 0;
            m_nMaxIndex = 0;
            m_vHash.resize(_num_primes[m_nMaxIndex]);
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

    private:
        void _hash_func(int key)
        {
            return key % _num_primes[m_nMaxIndex];
        }

        void _resize(int count)
        {
            std::vector<DoubleLinkedList < std::pair<key_type, value_type> > > tempHash = new
                std::vector<DoubleLinkedList < std::pair<key_type, value_type> > >(count);
            tempHash.swap(m_vHash);
            for (int i = 0; i < tempHash.size(); ++i)
            {
                DoubleLinkedList < std::pair<key_type, value_type>>& dlList = tempHash[i];
                DLListNode<std::pair<key_type, value_type>> dlNode =  dlList.pop_front();
                
            }
        }

        std::vector<DoubleLinkedList < std::pair<key_type, value_type> > > m_vHash;
        int m_nCurr;
        int m_nMaxIndex;
    };
}
#endif // !__LIST_DEF_H__