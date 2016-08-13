class Queue {
public:
    stack<int> stack1;
    stack<int> stack2;

    Queue() {
        while(!stack1.empty())
            stack1.pop();
        while(!stack2.empty())
            stack2.pop();
    }

    void push(int element) {
        stack1.push(element);
    }
    
    int pop() {
        if(stack2.empty())
            while(!stack1.empty()) {
                auto t = stack1.top();
                stack1.pop();
                stack2.push(t);
            }
        auto t = stack2.top();
        stack2.pop();
        return t;
    }

    int top() {
        if(stack2.empty())
            while(!stack1.empty()) {
                auto t = stack1.top();
                stack1.pop();
                stack2.push(t);
            }
        return stack2.top();
    }
};
