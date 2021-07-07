/*
*   动态规划： 把绳子划分为1，对乘积没有任何作用，所以从2开始划分
*   dp数组的定义：长度为i的绳子的乘积的最大值
* 
*/

class Solution {
public:
    int cuttingRope(int n) {

        if(n == 2) return 1;
        vector<int>dp(n+1,0);    //长度为i的绳子的最大乘积是dp[i]
        dp[2] = 1;
        dp[3] = 2;
        for(int i = 4; i<= n; i++) { // 递推，从长度为4的绳子开始递推，一直到长度为n，每次算出长度为i的最大乘积
            for(int j = 2; j < i -1; j++) { //每次剪的长度，从长度为2开始剪:长度为j的时候 先剪去j,然后剩下的i-j
                                            //有两种选择：剪或不剪，取最大。如果不剪就是j*(i -j),如果剪的话是j*dp[i-j]
                                            // 然后在j的不同的情况中取最大值
                dp[i] = max(dp[i], max(j*(i -j), j*dp[i-j]));
            }
        }
        return dp[n];
     }
};
