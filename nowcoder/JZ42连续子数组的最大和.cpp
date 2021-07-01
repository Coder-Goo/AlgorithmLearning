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
//         - 当dp[i-1]<=0; 执行dp[i] = nums[i];

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.size()<1) rerturn 0;
        vector<int> dp(nums.size(), 0);
        for(int i = 1; i< nums.size(); i++) {
            if(dp[i-1] <= nums[i]) dp[i] = nums[i];
            else dp[i] = dp[i-1] + max(nums[i], 0);
        }
        return dp[nums.size() -1];
    }
};