#ifndef _LEETCODE__H_
#define _LEETCODE__H_
#include "stdafx.h"
#include "ListDef.h"
#include "146_LRU_Cache.h"
#include "706_Design_HashMap.h"
#include "707_Design_Linked_List.h"
namespace Solution {
    static const auto io_sync_off = []()
    {
        // turn off sync
        std::ios::sync_with_stdio(false);
        // untie in/out streams
        std::cin.tie(nullptr);
        return nullptr;
    }();

}

#endif // !_LEETCODE__H_

