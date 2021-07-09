// 要求：
//     输入 nums = [ -2,1,-3,4,-1,2,1,-5,4];
//     输出 6；
//     解释：连续子数组[4,-1,2,1]的和最大，为6

// 思路：
//     求最值
//     遍历，以第i个元素结尾的数组的最大子数组的和，找出最大的，就是整个数组的最大值
//     动态规划
//     dp[i]定义为以第i个元素结尾的连续数组的最大和
//     以第i个元素结尾这样的设定才好设计第i个元素nums[i]的转移方程
    
//     转移方程： 如果dp[i-1]<= 0; 那么说明dp[i-1] 对dp[i]产生负贡献，即dp[i-1] + nums[i]
//     还不如nums[i]本身大。那么nums[i]就自成一块，因为要满足连续要求
//         - 当dp[i-1]>0; 执行dp[i] = dp[i-1]+ nums[i];
//         - 当dp[i-1]<=0; 执行dp[i] = nums[i] + 0;


//动态规划,dp[i]表示第i个元素结尾的 最大连续子序列 和，那么我们就是求max(d[i])
//如果数组为【a,b,c，d】,那么以2结尾的子数组为【a,b,c】[b,c][c]
//最大和的为【b,c】;那么以3结尾的就有两种选择【b,c,d】或【d】;因为【a,b,c】或【c】加上d肯定小于【b,c】加上d
//那么就是dp[i]= max(dp[i-1]+nums[i],nums[i]);

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        vector<int>dp(nums.size(), 0);
        dp[0] = nums[0];
        int result = dp[0];
        for(int i= 1; i < nums.size(); ++i) {
            dp[i] = max(dp[i-1]+nums[i],nums[i]);
            if(dp[i]>result) {
                result = dp[i];
            }
        }
        return result;
    }
};


//暴力解法;

// class Solution {
// public:
//     int maxSubArray(vector<int>& nums) {
//         int result = INT_MIN;
//         for(int i = 0; i< nums.size(); ++i) {
//             int count = 0;
//             for(int j = i ; j<nums.size(); ++j) {
//                 count += nums[j];
//                 result = result > count ? result : count;
//             }

//         }
//         return result;
//      }
// };

//贪心算法  ;因为加上负数只会减少总和，那么如果加上一个数后总和变为负值，那么总和从下一个数开始算起，这就是贪心的地方
// class Solution {
// public:
//     int maxSubArray(vector<int>& nums) {
//         int result = INT_MIN;
//         int count = 0;
//         for(int i =0 ; i< nums.size(); ++i) {
//             count += nums[i];
//             if(count > result) {
//                 result = count;
//             }
//             if(count<0) {
//                 count = 0;
//             }
//         }
//         return result;
//     }
// };

