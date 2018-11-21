static const auto io_sync_off = []()
{
    // turn off sync
    std::ios::sync_with_stdio(false);
    // untie in/out streams
    std::cin.tie(nullptr);
    return nullptr;
}();
class MinStack {
public:
    /** initialize your data structure here. */
    typedef struct ListNode
    {
        int val;
        int minVal;
        struct ListNode* next;
        ListNode(int value, int minValue)
        {
            val = value;
            minVal = minValue;
            next = nullptr;
        }
    }ListNode;
    ListNode* head;
    MinStack() {
        head = nullptr;
    }
    
    void push(int x) {
        if(nullptr == head)
        {
            ListNode* node = new ListNode(x, x);
            head = node;
            return;
        }
        ListNode* node = new ListNode(x, std::min(head->minVal, x));
        node->next = head;
        head = node;
    }
    
    void pop() {
        if(nullptr == head)
            return;
        ListNode* node = head;
        head = head->next;
        delete node;
    }
    
    int top() {
        if(nullptr == head)
            return 0;
        return head->val;
    }
    
    int getMin() {
        if(nullptr == head)
            return 0;
        return head->minVal;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */