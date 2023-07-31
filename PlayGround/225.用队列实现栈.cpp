/*
 * @lc app=leetcode.cn id=225 lang=cpp
 *
 * [225] 用队列实现栈
 */

// @lc code=start
class MyStack {
public:
    MyStack() {

    }
    queue<int> q1;
    queue<int> q2;
    void push(int x) {
        q1.push(x);
        while(!q2.empty())
        {
            int tmp = q2.front();
            q2.pop();
            q1.push(tmp);
        }
        queue<int> tmpq = q1;
        q1 = q2;
        q2 = tmpq;
    }
    
    int pop() {
        int tmp = q2.front();
        q2.pop();
        return tmp;
    }
    
    int top() {
        return q2.front();
    }
    
    bool empty() {
        return q1.empty() && q2.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
// @lc code=end

