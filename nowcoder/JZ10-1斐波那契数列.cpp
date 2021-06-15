
//递归方法，容易超出时间限制
class Solution {
public:
    int fib(int n) {
        if(n == 0 ) return 0;
        if(n == 1) return 1;
        return fib(n -1) + fib(n -2);
    }
};

//跌代法：
class Solution {
public:
    int fib(int n) {
        if(n == 0) return 0;
        if(n == 1) return 1;
        long pre = 0;
        long cur = 1;
        long result = 0;
        for(int i = 2; i<=n; i++) {
            result = (pre + cur)%1000000007;  //取模运算是题目要求的
            pre = cur;
            cur = result;
        }
        return result;
    }
};