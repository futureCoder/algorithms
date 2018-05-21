/*
给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序。
示例:
输入: [0,1,0,3,12]
输出: [1,3,12,0,0]
说明:
必须在原数组上操作，不能拷贝额外的数组。
尽量减少操作次数。
 */
static const auto __ = []()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int rear = 0, front = 0;
        while(front < nums.size())
        {
            if(nums[front] != 0)
                nums[rear++] = nums[front];
            ++front;
        }
        while(rear < nums.size())
            nums[rear++] = 0;
    }
};