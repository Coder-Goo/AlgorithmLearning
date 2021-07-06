//和 打家劫舍 类似
//动态规划：dp[i]以下标为i的元素结尾的子数组的翻译的字符串个数
//下标为i个元素有两个选择： 要么自成一派，要么和前一个元素i-1组团，但是45这样和02这样是组不了团的
//  - 自成一派，那么i个元素的贡献就是dp[i-1]
//  - 如果和前面的元素组成团体在10~25之间，那么可以组团，贡献为dp[i-2]
//那么dp[i] = dp[i-1] + dp[i-2];
class Solution {
public:
    int translateNum(int num) {
        string s = to_string(num);
        vector<int> dp(s.size()+1,0);
        
        dp[0]=1, dp[1] = 1;
        for(int i = 2; i<=s.size(); i++) {
            string str = s.substr(i-2, 2);
            if("10" <= str && str<="25") {
                dp[i] = dp[i-1] + dp[i-2];
            } else dp[i] = dp[i-1];
        }
        return dp[s.size()];
    }
};

//取字符串的i-1和i-2个字符组成新字符串： s[i-1] + s[i-1]是不对的，两个字符相加的结果是ascii码相加
//取子串：s.substr(i -2, 2);表示从i-2开始取两个
//位于10~25之间应该是"10"<=str && str<= "25"; 而不是    '10'=<str<='25'