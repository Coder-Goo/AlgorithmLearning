
//最长 字符串  动态规划 or 滑动窗口

dp[i]表示以第i个字符以前的最长子串的长度; 
    那么看s[i],前面有和s[i]相同的字符的位置为j; 
        - 如果 j<0; 那么dp[i] = dp[i-1] +1;
        - 如果 i -j > dp[i-1]; 那么dp[i] = dp[i-1] + 1;
        - 如果 i -j =< dp[i-1]; 那么dp[i] = i-j;

//动态规划：使用线性遍历方法来寻找与s[i]相等s[j]
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        vector<int> dp(n, 0);
        if(n == 0) return 0;
        dp[0] = 1;
        int res = 1;
        for(int i = 1; i< n; i++) {
            int j = i-1;
            for(; j>= 0; j--) {
                if(s[i] == s[j]) break;
                else if(j == 0 && s[i] != s[j]) {
                    j = -1;
                    break;
                }
            }
            if(dp[i-1] < i -j) dp[i] = dp[i-1] +1;
            else dp[i] = i -j;
            res = max(res,dp[i]);
        }
        return res;
    }
};

//动态规划：使用map来存储s[i]对应的下标，如何更新？ ： 用下标直接更新

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        vector<int> dp(n, 0);
        if(n == 0) return 0;
        dp[0] = 1;
        int res = 1;
        map<char, int>my_map;
        for(int i = 1; i< n; i++) {
            int j =my_map[s[i]];
            if(i -j > dp[i-1] || (j == 0 && s[i]!= s[j])) dp[i] = dp[i-1] +1;
            else dp[i] = i-j;
            my_map[s[i]] = i;
            res = max(res,dp[i]);

        }
        return res;
    }
};

//滑动窗口：当窗口中出现重复字符时，需要缩减窗口
//可以使用set来看窗口中是否包含当前元素；包含了如何移除set里的元素？s.erase(p);p可以是元素也可以是迭代器
//不需要有序，可以使用unordered_set;如何查看unordered_set里有没有这个元素？set容器类不支持下标操作，只有map类容器
//支持下标操作
