class MinStack {
public:
    /** initialize your data structure here. */
    vector<long> S;
    long min_element;
    
    MinStack() {
    }
    void push(int x) {
        long xt = (long)x;
        if(S.empty())
        {
           S.push_back(xt);
            min_element = xt;
        }
        else if(min_element>xt)
        {
            S.push_back(2*xt-min_element);
            min_element = xt;
        }
        else
        {
            S.push_back(xt);
        }
    }
    
    void pop() {
        if(S.back()<min_element)
        {
            min_element = (int)((min_element + min_element)- S.back());
        }
        S.pop_back();
    }
    
    int top() {
        return (int)((S.back()<min_element)?min_element:S.back());
    }
    
    int getMin() {
        return (int)min_element;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */