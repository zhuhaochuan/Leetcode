
//面试系列的问题
//使用栈构成队列简单
//使用两个队列构成栈就有点意思了
//关键在于同一时刻有一个队列必须为空
//这样在插入元素的时候，先将元素插入到空队列当中
//就构成了插在队列头部的作用 使得出栈的时候出的是队列的头部元素

class MyStack {
public:
    queue<int> q1,q2;
    /** Initialize your data structure here. */
    MyStack() {

    }

    /** Push element x onto stack. */
    void push(int x) {
        if(q1.empty()) {
            q1.push(x);
            while(!q2.empty()) {
                q1.push(q2.front());
                q2.pop();
            }
        }
        else {
            q2.push(x);
            while(!q1.empty()) {
                q2.push(q1.front());
                q1.pop();
            }
        }
    }

    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int res = 0;
        if(!q1.empty()) {
            res = q1.front();
            q1.pop();
        }
        else {
            res = q2.front();
            q2.pop();
        }
        return res;
    }

    /** Get the top element. */
    int top() {
        int res = 0;
        if(!q1.empty()) {
            res = q1.front();
        }
        else {
            res = q2.front();
        }
        return res;
    }

    /** Returns whether the stack is empty. */
    bool empty() {
        return q1.empty()&&q2.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack obj = new MyStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.top();
 * bool param_4 = obj.empty();
 */