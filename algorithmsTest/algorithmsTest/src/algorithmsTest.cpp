#include "stdafx.h"
#include "BasicAlgorithms.h"
#include <Windows.h>
#include <algorithm>
#include "LeetCode.h"

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

//namespace Solution120
//{
//    using namespace std;
//    class Solution {
//    public:
//        int minimumTotal(vector<vector<int>>& triangle) {
//            if (triangle.empty())
//                return 0;
//            for (int i = 1; i < triangle.size(); ++i)
//            {
//                for (int j = 0; j < triangle[i].size(); ++j)
//                {
//                    if (j - 1 < 0)
//                        triangle[i][j] += triangle[i - 1][j];
//                    else
//                        triangle[i][j] = min(1, 2);
//                }
//            }
//            return __GetMin(triangle[triangle.size() - 1]);
//        }
//    private:
//        int __GetMin(vector<int>& vec)
//        {
//            int nMin = vec[0];
//            for (auto i : vec)
//                nMin = std::min(nMin, i);
//            return nMin;
//        }
//    };
//    void main()
//    {
//
//    }
//}
//
//void print()
//{
//
//}
//
//template<typename T, typename... Types>
//void print(const T& firstArg, const Types&... args)
//{
//    cout << firstArg << endl;
//    print(args...);
//}
//
//int main()
//{
//    print(7.5, "hello", bitset<16>(377), 42);
//    /*std::vector<int> vec1 = { -1,0,1,2,-1,-4 };
//    std::string str = "ccc";
//    Solution1 s;
//	auto res = s.threeSum(vec1);*/
//    system("Pause");
//typedef union _addrlong
//{
//    long nAddr;
//    char strAddr[sizeof(long)];
//}_addrlong;
//
//namespace CommonFunc
//{
//
//    // INSERT_ELEMENTS (collection, first, last)
//    // - fill values from first to last into the collection
//    // - NOTE: NO half-open range
//    template <typename T>
//    inline void INSERT_ELEMENTS(T& coll, int first, int last)
//    {
//        for (int i = first; i <= last; ++i) {
//            coll.insert(coll.end(), i);
//        }
//    }
//
//    // PRINT_ELEMENTS()
//    // - prints optional string optstr followed by
//    // - all elements of the collection coll
//    // - in one line, separated by spaces
//    template <typename T>
//    inline void PRINT_ELEMENTS(const T& coll,
//        const std::string& optstr = "")
//    {
//        std::cout << optstr;
//        for (const auto& elem : coll) {
//            std::cout << elem << " ";
//        }
//        std::cout << std::endl;
//    }
//
//
//}
//
//namespace TestVector
//{
//    using namespace CommonFunc;
//    int main()
//    {
//        vector<int> coll;
//        INSERT_ELEMENTS(coll, 2, 6);
//        INSERT_ELEMENTS(coll, 4, 9);
//        INSERT_ELEMENTS(coll, 1, 7);
//        PRINT_ELEMENTS(coll, "coll:\t\t\t");
//        // remove all elements with value 5
//        vector<int>::iterator pos;
//        pos = remove(coll.begin(), coll.end(), // range
//            100); // value to remove
//        PRINT_ELEMENTS(coll, "size not changed:\t");
//        while (pos != coll.end())
//        {
//            *pos++ = 0;
//        }
//        PRINT_ELEMENTS(coll, "size not changed:\t");
//        // erase the ����removed���� elements in the container
//        coll.erase(pos, coll.end());
//        PRINT_ELEMENTS(coll, "size changed:\t\t");
//        // remove all elements less than 4
//        coll.erase(remove_if(coll.begin(), coll.end(), // range
//            [](int elem) { // remove criterion
//            return elem < 4;
//        }),
//            coll.end());
//        PRINT_ELEMENTS(coll, "<4 removed:\t\t");
//        return 0;
//    }
//}
//
//void print() {
//    cout << "empty" << endl;
//}
////չ������
//template<class T, class... Args>
//void print(T head, Args... rest) {
//    cout << "parameter = " << head << endl;
//    print(rest...);
//}
//
//std::list<int> GetList()
//{
//    std::list<int> list;
//    list.push_back(1);
//    list.push_back(2);
//    list.push_back(3);
//    return list;
//}
//
////int main() {
////    
////    print(1, 2, 3, 4);
////    /*std::list<int> l = GetList();
////    for (std::list<int>::iterator iter = l.begin(); iter != l.end(); ++iter)
////    {
////        std::cout << *iter << std::endl;
////    }*/
////    return 0;
////}
//

template<typename T>
T MyMax(T lhs, T rhs)
{
	return max(lhs, rhs);
}
template<typename T = int, typename... args>
T MyMax(T lhs, args... rhs)
{
	T _max = MyMax(rhs...);
	return max(lhs, _max);
}

class GridA
{
public:

	GridA(){}
	~GridA(){}
private:
	bool m_bWalk{};
	int m_nHeight{0};
	bool m_bValid{};
};

class GridB
{
public:

	GridB()
	{
	}
	virtual ~GridB();
private:
	int m_nAttrs{ 0 };
	int m_nHeight{ 0 };
};

void(*ppp[5])(int);

void Func(int a)
{
	
}

class Base
{
public:
	virtual void output() = 0
	{
		std::cout << "Base!" << std::endl;
	}
};
class Derived : public Base
{
public:
	virtual void output()
	{
		Base::output();
		std::cout << "Derived!" << std::endl;
	}
};

#include <iostream>
#pragma pack(2)
struct S1
{
	S1() { b = 0x02; c = 0x04; d = 0x08; e = 0x10; }
	float b;
	short c;
	int d;
	char e;
};
#pragma pack(push)
#pragma pack(16)
struct S2
{
	S2() { a = 0x01; f = 0x20; g = 0x30; h = 0xF0F0F0F0F0F0F0F0; }
	double a;
	S1 s1;
	long long int f;
	int g;
	long long int h;
};
#pragma pack(pop)

template<typename T>
T fun(T x, T y)
{
	return x*x + y*y;
}

int main()
{
	S2 x;
	S2 *px = &x;
	std::cout << sizeof(S1) << std::endl;
	std::cout << sizeof(x) << std::endl;

	//std::cout << fun(2.3, 8) << std::endl;
	//std::cout << fun<int>(2, 8.3) << std::endl;

	return 0;
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