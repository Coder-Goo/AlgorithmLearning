#include<stack>
#include<vector>

using namespace std;


/*
//思路：  双指针： i和j
//        1. 判断pushV[i]和popV[j]的值是否相同
//        2. 如果不相等，说明被压入栈，没有立即弹出，那么将pushV里的元素压入辅助栈，i++
//        3. 如果相等了，那么就说明开始弹出了，弹出的元素等于栈顶元素 j++ stk.pop() 
//        4. 如果不等于栈顶元素，说明又发生了压栈，再继续2,3步
//        5. 如果pushV被遍历完，那么判断popV有没有被遍历完全且判断栈是否为空
*/
class Solution {
private:
    std::stack<int>stk;

public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
        int i = 0, j= 0;
        for(; i< pushV.size(); i++) {
            if(pushV[i] != popV[j]) {
                stk.push(pushV[i]);
                continue;
            } else {  //
                j++;
    //while(popV[j] == stk.top() && j< popV.size() && !stk.empty()) {   //这里判断j是否越界的条件要首先判断，否则发生越界错误
                while( j< popV.size() && !stk.empty() && popV[j] == stk.top()) {
                    j++;
                    stk.pop();
                }
            }
        }
        if(i != j) return false;
        else return true;
    }
};