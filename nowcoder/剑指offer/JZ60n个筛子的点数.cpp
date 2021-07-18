
//dp[i][j]表示第i个筛子 得到 点数j的概率
//那么第 dp[i-1] [k] 分别有1/6的概率为[1,2,3,4,5,6]中一个，所以第i-1个点数为k的 情况对第i个 的贡献为
//dp[i][k+x] += dp[i-1][k]*1/6;    x = 1,2,3,4,5,6

class Solution {
public:
    vector<double> dicesProbability(int n) {
        vector<vector<double>>dp(12, vector<double>(72+1, 0));
        for(int i = 1; i<= 6; i++) {
            dp[1][i] = 1.0/6.0;
        }
        for(int i = 2; i<= n; i++) {
           for(int j = i -1 ; j<= 6* i; j++) {
               for(int k = 1; k<= 6; k++) {
                   dp[i][j + k] += dp[i-1][j] * (1.0/6.0);
               }   
           } 
        }
        vector<double> result;
        for(int i = n; i<=6*n; i++ ) result.push_back(dp[n][i]);
        return result;
    }
};