
二维dp的代表：

两个数组的最长公共子序列；那么就得二维遍历；最长 + 子序列 问题：动态规划DP
dp[i][j]表示s1[0~i-1] 和 s1[0~j-1];即以第i个和第j个字符结尾得字符串得最长公共子序列。
状态转移方程：
    (1)如果s1[i-1] = s2[j-1]; 那么dp[i][j] = 1+ dp[i-1][j-1];
    (2)如果s1[i-1]!= s2[j-1]; 那么dp[i][j] = max(dp[i-1][j], dp[i][j-1]);

如果相等，那么加1；如果不相等，那么说明有一个不在公共序列中，分别对s1和s2去除一个后选取最大值


```cpp
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size();
        int n = text2.size();
        if(m == 0 || n == 0) return 0;
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        for(int i = 0; i< m; i++) dp[i][0] = 0; // 表示text2的空串和任何字符的公共部分都是0
        for(int j = 0; j< n; j++) dp[0][j] = 0; //表示text1的空串和任何字符的公共部分都是0
        for(int i = 0; i< m; i ++) {
            for(int j = 0; j< n; j++) {
                if(text1[i] == text2[j]) dp[i+1][j+1] = 1+ dp[i][j];
                else dp[i+1][j+1] = max(dp[i][j+1], dp[i+1][j]);
            }
        } 
        return dp[m][n];
    }
};
```