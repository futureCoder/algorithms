/*
在 O(n log n) 时间复杂度和常数级空间复杂度下，对链表进行排序。
示例 1:
输入: 4->2->1->3
输出: 1->2->3->4

示例 2:
输入: -1->5->3->4->0
输出: -1->0->3->4->5
*/
/*
思路：题目要求 时间复杂度为 O(n log n),符合这个复杂度的常规排序算法有：快排、堆排、归并、希尔（？），其空间复杂度为：快排 O(log n)，堆排 O(1)，归并 数组下为O(n)、链表情况为O(1)，希尔 O(r)，
但快排、归并一般都要使用递归方法，如果把递归栈算入空间复杂度下，则都是O(log n)的空间复杂度，但用堆排对链表操作又过于复杂，所以还是选归并。
*/
static const auto __ = []()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        
    }
};