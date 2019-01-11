#ifndef _HASH_MAP_DEF__H_
#define _HASH_MAP_DEF__H_
#include "stdafx.h"
#include "ListDef.h"
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
    class HashNode
    {
    public:
        typedef KeyType key_type;
        typedef ValueType value_type;
        HashNode(key_type key, value_type val):
            m_key(key),
            m_val(val),
            m_pNext(nullptr)
        {}
        virtual ~HashNode()
        {}
        key_type m_key;
        value_type m_val;
        HashNode<key_type, value_type>* m_pNext;
    };

    template <typename KeyType, typename ValueType, typename HashFunc = _HashFunc<KeyType>>
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
            m_vHash.resize(capacity());
        }

        //template
        void put(int key, int value) {
            if (m_nCurr >= capacity())
            {
                size_t oldCapacity = capacity();
                m_nMaxIndex = std::min(m_nMaxIndex + 1, _num_primes);
                _resize(capacity());
            }
            size_t pos = _hash_func(key);
            HashNode<key_type, value_type>* newNode = new HashNode<key_type, value_type>(key, value);
            newNode->m_pNext = m_vHash[pos];
            m_vHash[pos] = newNode;
        }

        /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
        int get(int key) {
            size_t pos = _hash_func(key);
            const HashNode<key_type, value_type>* node = m_vHash[pos];
            while (node)
            {
                if (node->m_key == key)
                    return node->m_val;
                node = node->m_pNext;
            }
            return -1;
        }

        /** Removes the mapping of the specified value key if this map contains a mapping for the key */
        void remove(int key) {
            size_t pos = _hash_func(key);
            const HashNode<key_type, value_type>* node = m_vHash[pos];
        }

    private:
        size_t _hash_func(KeyType key)
        {
            return HashFunc(key, capacity);
            //return key % _num_primes[m_nMaxIndex];
        }

        size_t capacity()
        {
            return _prime_list[m_nMaxIndex];
        }

        void _resize(int count)
        {
            std::vector<HashNode<key_type, value_type>*> tempHash = new
                std::vector<HashNode<key_type, value_type>*>(count);
            tempHash.swap(m_vHash);
            for (std::vector<HashNode<key_type, value_type>*>::iterator iter = tempHash.begin(); iter != tempHash.end(); ++iter)
            {
                put(iter->m_key, iter->m_val);
            }
        }

        std::vector<HashNode<key_type, value_type>*> m_vHash;
        size_t m_nCurr;
        size_t m_nMaxIndex;
    };
}
#endif // !_HASH_MAP_DEF__H_