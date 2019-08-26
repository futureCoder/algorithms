#include "stdafx.h"
#include "BasicAlgorithms.h"
#include <Windows.h>
#include <algorithm>
#include "LeetCode.h"

using namespace std;

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


int main()
{
	LeetCode0000::Solution s;
	string str;
	int vList[6] = { 1,2,3,4,5,6 };
	s.Sererialize(str, 1, vList);
	cout << str << endl;
	//LeetCode347::main();
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