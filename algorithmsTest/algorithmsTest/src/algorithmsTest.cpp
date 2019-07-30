#include "stdafx.h"
#include "leetcode.h"
#include "BasicAlgorithms.h"
#include <Windows.h>
#include <algorithm>

#include "../Singleton.h"

using namespace std;

namespace Solution {
    int main()
    {
        //MyLinkedList* obj = new MyLinkedList();
        //obj->addAtHead(38);
        //obj->addAtHead(45);
        //obj->deleteAtIndex(2);
        //obj->addAtIndex(1, 24);
        //obj->deleteAtIndex(1);
        //obj->deleteAtIndex(1);
        //obj->deleteAtIndex(0);
        //obj->addAtHead(1);
        //obj->addAtHead(2);
        //obj->addAtIndex(1, 3);
        //obj->deleteAtIndex(1);
        //obj->deleteAtIndex(1);
        //obj->deleteAtIndex(0);
        //obj->addAtHead(1);
        //obj->addAtHead(2);
        //obj->addAtIndex(1, 3);
        //obj->deleteAtIndex(1);
        //obj->deleteAtIndex(1);
        //obj->deleteAtIndex(0);
        //getchar();
        return 0;
    }
    //class Solution1 {
    //public:
    //    vector<string> alphabeta = { "", "", "abc", "def",
    //        "ghi", "jkl", "mno",
    //        "pqrs", "tuv", "wxyz"
    //    };
    //    vector<string> letterCombinations(string digits) {
    //        vector<string> ret;
    //        if (digits.empty())
    //            return ret;
    //        return letterCombinations_(digits);
    //    }

    //    vector<string> letterCombinations_(string digits)
    //    {
    //        if (digits.size() == 1)
    //        {
    //            vector<string> ret;
    //            int num = stoi(digits);
    //            for (int i = 0; i < alphabeta[num].size(); ++i)
    //            {
    //                ret.push_back(to_string(alphabeta[num][i]));
    //            }
    //            return ret;
    //        }
    //        vector<string> res = letterCombinations_(digits.substr(1));
    //        vector<string> ret;
    //        for (auto str : res)
    //        {
    //            for (auto ch : alphabeta[pos][digits[0] - '0'])
    //            {
    //                ret.push_back(ch + str);
    //            }
    //        }
    //        return ret;
    //    }
    //};
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
typedef union _addrlong
{
    long nAddr;
    char strAddr[sizeof(long)];
}_addrlong;

namespace CommonFunc
{

    // INSERT_ELEMENTS (collection, first, last)
    // - fill values from first to last into the collection
    // - NOTE: NO half-open range
    template <typename T>
    inline void INSERT_ELEMENTS(T& coll, int first, int last)
    {
        for (int i = first; i <= last; ++i) {
            coll.insert(coll.end(), i);
        }
    }

    // PRINT_ELEMENTS()
    // - prints optional string optstr followed by
    // - all elements of the collection coll
    // - in one line, separated by spaces
    template <typename T>
    inline void PRINT_ELEMENTS(const T& coll,
        const std::string& optstr = "")
    {
        std::cout << optstr;
        for (const auto& elem : coll) {
            std::cout << elem << " ";
        }
        std::cout << std::endl;
    }


}

namespace TestVector
{
    using namespace CommonFunc;
    int main()
    {
        vector<int> coll;
        INSERT_ELEMENTS(coll, 2, 6);
        INSERT_ELEMENTS(coll, 4, 9);
        INSERT_ELEMENTS(coll, 1, 7);
        PRINT_ELEMENTS(coll, "coll:\t\t\t");
        // remove all elements with value 5
        vector<int>::iterator pos;
        pos = remove(coll.begin(), coll.end(), // range
            100); // value to remove
        PRINT_ELEMENTS(coll, "size not changed:\t");
        while (pos != coll.end())
        {
            *pos++ = 0;
        }
        PRINT_ELEMENTS(coll, "size not changed:\t");
        // erase the ¡®¡®removed¡¯¡¯ elements in the container
        coll.erase(pos, coll.end());
        PRINT_ELEMENTS(coll, "size changed:\t\t");
        // remove all elements less than 4
        coll.erase(remove_if(coll.begin(), coll.end(), // range
            [](int elem) { // remove criterion
            return elem < 4;
        }),
            coll.end());
        PRINT_ELEMENTS(coll, "<4 removed:\t\t");
        return 0;
    }
}

void print() {
    cout << "empty" << endl;
}
//Õ¹¿ªº¯Êý
template<class T, class... Args>
void print(T head, Args... rest) {
    cout << "parameter = " << head << endl;
    print(rest...);
}

std::list<int> GetList()
{
    std::list<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    return list;
}

class SinTest : public Singleton<SinTest>
{
public:
    void Show()
    {
        print(1, 1, 2, 2, 3, 4, 5);
    }
protected:
private:
    SinTest();
    ~SinTest();
    friend class Singleton<SinTest>;
};

//int main() {
//    
//    print(1, 2, 3, 4);
//    /*std::list<int> l = GetList();
//    for (std::list<int>::iterator iter = l.begin(); iter != l.end(); ++iter)
//    {
//        std::cout << *iter << std::endl;
//    }*/
//    return 0;
//}
namespace TestCast
{
    class A
    {
    public:
        A() {}
        virtual ~A() {}
        int i;
    };

    class B :public A
    {
    public:
        B() {}
        virtual ~B() {}
        int j;
    };
    class C :public B
    {
    public:
        C() {}
        virtual ~C() {}
        int k;
    };
    class D :public C
    {
    public:
        D() {}
        virtual ~D() {}
        int l;
    };
    class E :public D
    {
    public:
        E() {}
        virtual ~E() {}
        int m;
    };
    int main()
    {
        E* pE = new E;
        A* pA = new E;


        int st = GetTickCount();
        for (int i = 0; i != 100000000; i++)
        {
            pE = (E*)pA;
        }
        int en = GetTickCount();

        int st1 = GetTickCount();
        for (int i = 0; i != 100000000; i++)
        {
            pE = static_cast<E*>(pA);
        }
        int en1 = GetTickCount();

        int st2 = GetTickCount();
        for (int i = 0; i != 100000000; i++)
        {
            pE = dynamic_cast<E*>(pA);
        }
        int en2 = GetTickCount();

        cout << "():" << (en - st) << endl;
        cout << "static_cast:" << (en1 - st1) << endl;
        cout << "dynamic_cast:" << (en2 - en1) << endl;
        return 0;
    }
}


namespace LeetCode132
{
    int minCut(string s) {
        const int nSize = s.size();
        int* f = new int[nSize];
        bool** isPalindrome = new bool*[nSize];
        for(int i = 0; i < nSize; ++i)
        {
            isPalindrome[i] = new bool[nSize];
        }
        fill_n(&isPalindrome[0][0], nSize * nSize, false);
        for (int i = 0; i <= nSize; ++i)
            f[i] = nSize - i - 1;
        try
        {
            for (int i = nSize - 1; i >= 0;)
            {
                for (int j = i; j < nSize; ++j)
                {
                    if (s[i] == s[j] && (j - i < 2 || s[i + 1] == s[j - 1]))
                    {
                        isPalindrome[i][j] = true;
                        f[i] = min(f[i], f[j + 1] + 1);
                    }
                }
                --i;
            }
        }
        catch(exception e)
        {
            std::cout << e.what() << endl;
        }
        return f[0];
    }
}

int main()
{
    //TestVector::main();
    LeetCode132::minCut("amanaplanacanalpanama");
    return 0;
}

//int main()
//{
//    _addrlong addr;
//    addr.nAddr = 0x12345678;
//    for (int i = 0; i < sizeof(long); ++i)
//    {
//        cout << hex << addr.strAddr[i] << endl;
//    }
//    
//    //std::vector<int> vec1 = {-1, 0, 1, 2, -1, -4};
//    //std::string str = "23";
//    //Solution1 s;
//    //auto ans = s.letterCombinations(str);
//    //system("Pause");
//}

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
