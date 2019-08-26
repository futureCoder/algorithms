#ifndef __LEETCODE_H__
#define __LEETCODE_H__
#include "LeetCodeDef.h"
#include <iostream>
#include <algorithm>

namespace LeetCode56
{
	typedef pair<int, int> Interval;
	vector<Interval> __serialize(vector<vector<int>>& intervals);
	vector<vector<int>> __deserialize(vector<Interval>& intervals);
	void __merge(vector<Interval>& intervals);
	static bool cmp(const Interval& lhs, const Interval& rhs);
	void test();
}

namespace LeetCode0000
{
	class Solution
	{
	public:
		bool Sererialize(std::string& strGundam, int nID, int vModelList[6])
		{
			char str[32];
			memset(str, 0x00, 32);

			int size = 4;
			for (int i = 0; i < size; ++i)
			{
				str[i] |= ((nID >> (i * 6)) & 0x3f);
				for (int j = 0; j < 6; ++j)
				{
					int m = (j + 1) * size + i;
					str[m] |= ((vModelList[j] >> (m * 6)) & 0x3f);
				}
			}
			strGundam = str;
			return true;
		}
	};
}

namespace LeetCode347
{
	class Solution {
	public:
		vector<int> topKFrequent(vector<int>& nums, int k) {
			map<int, int> myMap;
			for (auto i : nums)
			{
				++myMap[i];
			}
			vector<pair<int, int>> vPairs;
			for (auto i : myMap)
			{
				vPairs.push_back(make_pair(i.first, i.second));
			}
			std::function<bool(pair<int, int>, pair<int, int>)> func([](const pair<int, int>& lhs, const pair<int, int>& rhs) -> bool
			{
				return rhs.second < lhs.second;
			});

			HeapSort<pair<int, int>>(vPairs, func, k);

			vector<int> vRet;
			for (int i = vPairs.size() - 1; i >= 0 && k > 0; --i, --k)
			{
				vRet.push_back(vPairs[i].first);
			}
			return vRet;
		}
	private:
		priority_queue<pair<int, int>> heap;
		bool cmp(pair<int, int> lhs, pair<int, int> rhs)
		{
			return rhs.second < lhs.second;
		}

		template<typename T>
		void HeapSort(vector<T>& heap, const function<bool(T, T)>& cmp, int k)
		{
			int nSize = heap.size();
			MakeHeap(heap, cmp);
			for (int i = nSize - 1; i >= nSize - k; --i)
			{
				swap(heap[0], heap[i]);
				HeapAdjust(heap, 0, i, cmp);
			}
		}
		template<typename T>
		void HeapAdjust(vector<T>& heap, int nIndex, int nLimit, const function<bool(T, T)>& cmp)
		{
			for (int nChild = 2 * nIndex + 1; nChild < nLimit; )
			{
				if (nChild + 1 < nLimit && cmp(heap[nChild + 1], heap[nChild]))
					++nChild;
				if (!cmp(heap[nChild], heap[nIndex]))
					break;
				swap(heap[nChild], heap[nIndex]);
				nIndex = nChild;
				nChild = 2 * nIndex + 1;
			}
		}
		template<typename T>
		void MakeHeap(vector<T>& heap, const function<bool(T, T)>& cmp)
		{
			int nSize = heap.size();
			for (int i = (nSize - 1) / 2; i >= 0; --i)
			{
				HeapAdjust(heap, i, nSize, cmp);
			}
		}
	};
	void main()
	{
		Solution s;
		vector<int> vec{ 1};
		s.topKFrequent(vec, 1);
	}
}

#endif // !__LEETCODE_H__
