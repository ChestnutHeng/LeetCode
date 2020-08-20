/*
 * @lc app=leetcode id=155 lang=cpp
 *
 * [155] Min Stack
 */

// @lc code=start

// 单调栈维护最小值
// 注意入栈条件，空或者小于等于最小值

class MinStack {
public:
    /** initialize your data structure here. */
    stack<int> minq;
    stack<int> q;
    MinStack() {
        
    }
    
    void push(int x) {
        q.push(x);
        if(minq.empty() || x <= minq.top()){
            minq.push(x);
        }
    }
    
    void pop() {
        int v = q.top();
        q.pop();
        if(v == minq.top()){
            minq.pop();
        }
    }
    
    int top() {
        return q.top();
    }
    
    int getMin() {
        return minq.top();
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
// @lc code=end

