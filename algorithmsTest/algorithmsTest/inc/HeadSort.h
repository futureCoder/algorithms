#include "Common.h"
void HeapSort(vector<int>& items, const function<bool(int, int)>& cmp);
void HeapInit(vector<int>& items, const function<bool(int, int)>& cmp);
void HeapAdjust(vector<int>& items, int nParent, int nLimit, const function<bool(int, int)>& cmp);

void HeapSort(vector<int>& items, const function<bool(int, int)>& cmp)
{
    HeapInit(items, cmp);
    for(int i = items.size() - 1; i > 0; --i)
    {
        swap(items[0], items[i]);
        HeapAdjust(items, 0, i, cmp);
    }
}
void HeapInit(vector<int>& items, const function<bool(int, int)>& cmp)
{
    for(int i = items.size() / 2; i >= 0; --i)
    {
        HeapAdjust(items, i, items.size(), cmp);
    }
}
void HeapAdjust(vector<int>& items, int nParent, int nLimit, const function<bool(int, int)>& cmp)
{
    if(nParent < 0)
        return;
    int nChild = 2 * nParent + 1;
    while(nChild < nLimit)
    {
        if(nChild + 1 < nLimit && cmp(items[nChild + 1], items[nChild]))
            ++nChild;
        if(cmp(items[nParent], items[nChild]))
            break;
        swap(items[nParent], items[nChild]);
        nParent = nChild;
        nChild = 2 * nParent + 1;
    }
}

bool Small(int l, int r)
{
    return l < r;
}