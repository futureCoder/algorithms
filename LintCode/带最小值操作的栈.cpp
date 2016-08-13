class MinStack {
public:
    MinStack() {
        // do initialization if necessary
    }

    void push(int number) {
        if(s.empty()) {
            m_nMin = number;
        }
        m_nMin = std::min(m_nMin, number);
        s.push(number);
        tmp.push(m_nMin);
    }

    int pop() {
        int ret = s.top();
        s.pop();
        tmp.pop();
        if(!tmp.empty())
            m_nMin = tmp.top();
        return ret;
    }

    int min() {
        if(!tmp.empty())
            return tmp.top();
    }
private:
    stack<int> s, tmp;
    int m_nMin;
};
