#include<vector>
using namespace std;

//方法一：动态规划，同斐波那契数列

//方法二：备忘录的递归：如下
class Solution {
public:
     
    int jumpFloor(int number) {
        if(number == 0) return 0;
        if(number == 1) return 1;
        vector<int> bp(number +1, -1);
        bp[0] = 0;
        bp[1] = 1;
        bp[2] = 2;
        return ReBack(number, bp);
    }
    int ReBack(int num, vector<int>& bp) {
        if(bp[num] != -1) return bp[num];
        else {
           bp[num] = ReBack(num -1,bp) + ReBack(num -2,bp);
        }
        return bp[num];
    }
};