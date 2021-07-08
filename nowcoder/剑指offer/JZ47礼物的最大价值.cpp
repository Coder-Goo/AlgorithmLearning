一个m*n的棋盘，可以从向下或向右走，问最多能拿到多大价值的礼物？

dp[i][j]定义为走到第i行第j列的最大值；
那么(i,j)只能从（i-1,j)过来或从（i,j-1）过来 
那么转移方程：
        dp[i][j] = max(dp[i-1][j] + value[i][j], dp[i][j-1] + value[i][j]);

base case ：
        第一行： 只能从左边过来，dp[i][0] = dp[i-1][0] + grid[i][0];
        第一列： 只能从上边下来，dp[0][j] = dp[[0]][j-1] + grid[0][j];

class Solution {
public:
    int maxValue(vector<vector<int>>& grid) {
        int m = grid.size();
        if(m == 0) return 0;
        int n = grid[0].size();
        if(n == 0) return 0;
        vector<vector<int>>dp(m,vector<int>(n,0));
        if(m ==1 && n ==1 ) return grid[0][0];
        //base case：
        dp[0][0] = grid[0][0];
        for(int i  = 1; i< m; i++ ) {
            dp[i][0] = dp[i-1][0] + grid[i][0];
        }
        for(int j = 1; j< n; j++) {
            dp[0][j] = dp[0][j-1] + grid[0][j];
        }      
        for(int i = 1; i< m; i++) {
            for(int j = 1; j< n; j++) {
                dp[i][j] = max(dp[i-1][j]+grid[i][j], dp[i][j-1] + grid[i][j]);
            }
        }
        return dp[m-1][n-1];
    }
};