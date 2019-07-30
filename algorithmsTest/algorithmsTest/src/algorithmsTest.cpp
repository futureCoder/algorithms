#include "stdafx.h"
#include "leetcode.h"
#include "BasicAlgorithms.h"
#include <Windows.h>

using namespace std;
using namespace Solution;
namespace Solution {
    int main()
    {
        MyLinkedList* obj = new MyLinkedList();
        obj->addAtHead(38);
        obj->addAtHead(45);
        obj->deleteAtIndex(2);
        obj->addAtIndex(1, 24);
        obj->deleteAtIndex(1);
        obj->deleteAtIndex(1);
        obj->deleteAtIndex(0);
        obj->addAtHead(1);
        obj->addAtHead(2);
        obj->addAtIndex(1, 3);
        obj->deleteAtIndex(1);
        obj->deleteAtIndex(1);
        obj->deleteAtIndex(0);
        obj->addAtHead(1);
        obj->addAtHead(2);
        obj->addAtIndex(1, 3);
        obj->deleteAtIndex(1);
        obj->deleteAtIndex(1);
        obj->deleteAtIndex(0);
        getchar();
        return 0;
    }
}

namespace Solution120
{
    using namespace std;
    class Solution {
    public:
        int minimumTotal(vector<vector<int>>& triangle) {
            if (triangle.empty())
                return 0;
            for (int i = 1; i < triangle.size(); ++i)
            {
                for (int j = 0; j < triangle[i].size(); ++j)
                {
                    if (j - 1 < 0)
                        triangle[i][j] += triangle[i - 1][j];
                    else
                        triangle[i][j] = min(1, 2);
                }
            }
            return __GetMin(triangle[triangle.size() - 1]);
        }
    private:
        int __GetMin(vector<int>& vec)
        {
            int nMin = vec[0];
            for (auto i : vec)
                nMin = std::min(nMin, i);
            return nMin;
        }
    };
    void main()
    {

    }
}

void print()
{

}

template<typename T, typename... Types>
void print(const T& firstArg, const Types&... args)
{
    cout << firstArg << endl;
    print(args...);
}

int main()
{
    print(7.5, "hello", bitset<16>(377), 42);
    /*std::vector<int> vec1 = { -1,0,1,2,-1,-4 };
    std::string str = "ccc";
    Solution1 s;
	auto res = s.threeSum(vec1);*/
    system("Pause");
}
//
//void makeNext(string needle, vector<int> &next)
//{
//    int k = -1;
//    for (int i = 1; i < needle.size(); ++i)
//    {
//        while (k > -1 && needle[k + 1] != needle[i])
//        {
//            k = next[k];
//        }
//        if (needle[k + 1] == needle[i])
//        {
//            ++k;
//        }
//        next[i] = k;
//    }
//}
//
//int kmp(string haystack, string needle)
//{
//    vector<int> next(needle.size(), -1);
//    makeNext(needle, next);
//    int k = -1;
//    for (int i = 0; i < haystack.size(); ++i)
//    {
//        while (k > -1 && needle[k + 1] != haystack[i])
//        {
//            k = next[k];
//        }
//        if (needle[k + 1] == haystack[i])
//        {
//            ++k;
//        }
//        if (k == needle.size() - 1)
//            return i - k;
//    }
//    return -1;
//}
//
//int strStr(string haystack, string needle) {
//    if (0 == needle.size())
//        return 0;
//    if (0 == haystack.size())
//        return -1;
//    return kmp(haystack, needle);
//}
//
///* type to ensure maximum alignment */
//#define LUAI_USER_ALIGNMENT_T	union { double u; void *s; long l; }
//typedef LUAI_USER_ALIGNMENT_T L_Umaxalign;
//#define CommonHeader	void *next; char tt; char marked
//typedef union TString {
//    L_Umaxalign dummy;  /* ensures maximum alignment for strings */
//    struct {
//        CommonHeader;
//        char reserved;
//        unsigned int hash;
//        size_t len;
//    } tsv;
//} TString;
//
//static const auto __ = []()
//{
//    ios::sync_with_stdio(false);
//    cin.tie(nullptr);
//    return nullptr;
//}();
//class Solu {
//public:
//    vector<vector<int>> threeSum(vector<int>& nums) {
//        std::vector<std::vector<int>> ret;
//        std::sort(nums.begin(), nums.end());
//        for (int i = 0; i < nums.size(); ++i)
//        {
//            while (i - 1 >= 0 && nums[i] == nums[i - 1])
//                ++i;
//            int target = -nums[i];
//            std::unordered_set<int> mySet;
//            for (int j = i + 1; j < nums.size(); ++j)
//            {
//                
//                if (mySet.end() != mySet.find(target - nums[j]))
//                {
//                    ret.push_back(vector<int>{nums[i], target - nums[j], nums[j]});
//                    while (j > i + 1 && j < nums.size() && nums[j] == nums[j - 1])
//                        ++j;
//                }
//                else
//                {
//                    mySet.insert(nums[j]);
//                }
//            }
//        }
//        return ret;
//    }
//};
//
//enum eAvatarBattleCardIDParamDef
//{
//    eBattleCardID_CURCARDID_OFFSET = (16 * 0),
//    eBattleCardID_ACTIVE_1_OFFSET = (16 * 1),
//    eBattleCardID_ACTIVE_2_OFFSET = (16 * 2),
//    eBattleCardID_ACTIVE_3_OFFSET = (16 * 3),
//    eBattleCardID_MASK = 0xffff,
//};
//
//
//#define SET_BIT_N_M(x,n,m,val)\
//    CLEAR_BIT_N_M(x,n,m);\
//    (x |= (((GETBITS(val,0,(m-n))) << (n))))
//
//#define CLEAR_BIT_N_M(x,n,m)\
//    (x &= ~((~((~0ui64) << (m-n))) << (n)))
//
//#define GETBITS(x,n,m)\
//    (( x & ((~((~0ui64) << (m-n))) << (n))) >> (n))
//
//int main()
//{
//    uint64_t val = 0xffffffffffffffff;
//    uint64_t templateval = 0x1234567887654321;
//    cout << hex << GETBITS(templateval, eBattleCardID_ACTIVE_3_OFFSET, eBattleCardID_ACTIVE_3_OFFSET + 16) << endl;
//    cout << hex << val << "->" << endl << CLEAR_BIT_N_M(val, eBattleCardID_ACTIVE_3_OFFSET, eBattleCardID_ACTIVE_3_OFFSET + 16) << endl;;
//    val = SET_BIT_N_M(val, eBattleCardID_ACTIVE_3_OFFSET, eBattleCardID_ACTIVE_3_OFFSET + 16,
//        0x1234);
//    cout << hex << val << endl;
//    //cout << hex << (1i64 << eBattleCardID_ACTIVE_3_OFFSET) << endl;
//    return 0;
//}
