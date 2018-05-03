class MinStack {
public:
    stack<int> s,mins;
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        s.push(x);
        if(mins.empty())
            mins.push(x);
        else {
            int min_val = mins.top();
            if(x>min_val)
                mins.push(min_val);
            else
                mins.push(x);
        }
    }
    
    void pop() {
        s.pop();
        mins.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return mins.top();
    }
};
//重点在于两个栈同步增长
/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */