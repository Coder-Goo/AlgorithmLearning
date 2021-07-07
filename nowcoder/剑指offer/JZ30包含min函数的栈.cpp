//定义数据结构，请在该类型中实现能得到栈中最小元素min的函数（时间复杂度为o(1))
#include<stack>

/*
    //使用一个最小变量来记录最小值，但是这个最小元素可能被出栈，导致失败！！！！
    //而且最小元素被弹出之后如何得到第二小的元素

    //思路：用一个辅助栈，插入元素时，栈顶保存最小元素
    //    插入元素时，如果要插入的元素大于栈顶元素，说明栈内最小元素不会改变，那么辅助栈上压入的是 此时辅助栈上的栈顶元素
    //    如果压入的元素较小，那么压入的是新元素

*/

class Solution {
    std::stack<int> stk, min_stk;
public:
    void push(int value) {
        if(stk.empty()) min_stk.push(value);
        else {
            if(value < min_stk.top()) min_stk.push(value);
            else min_stk.push(min_stk.top());
        }
        stk.push(value);
    }
    void pop() {
        stk.pop();
        min_stk.pop();
    }
    int top() {
        return stk.top();
    }
    int min() {
        return min_stk.top();
    }
};






/*//使用一个元素来记录最小的元素！！！错误

class Solution {
private:
    std::stack<int> stk;
    int min = INT_MIN, count = 0;
public:
    void push(int value) {
        if(value < min) min = value;
        stk.push(value); 
        count ++;
    }
    void pop() {
        if(count<= 0) throw "no element";
        stk.pop(); 
        count --;    
    }
    int top() {
        if(count<= 0) throw "no element";
        return stk.top();
    }
    int min() {
        if(count<= 0) throw "no element";
       return min; 
    }
};