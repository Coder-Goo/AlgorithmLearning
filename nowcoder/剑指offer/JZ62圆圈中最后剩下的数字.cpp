
圆圈中最后剩下的数字：
设f(n，m)为n个数中删除第m个，删除后为n-1个，则变为f(n-1, m)，就是在n-1中删除m个，这不就是
递归的性质吗？

f(n,m) = (f(n -1,m) + m) % n

class Solution {
public:
    int lastRemaining(int n, int m) {
        if(n<1 || m < 1) return -1;
        int last = 0;
        for(int i= 2; i<=n; i++) {
            last = (last+m)%i;
        }
        return last;
    }
};