//最高金额，动态规划
//dp[i]表示前i间房屋能偷窃得到的最高金额
//来到下标为i的房间有两种来法： 从i -1过来，从i -2 过来，
//  - 从i-1过来的时候，下标为i的不能偷了
//  - 从i-2过来的时候，下标为i的还可以偷
//取最大的

//dp[i] = max(dp[i-1] , nums[i] + dp[i-2])

//初始条件： dp[0] = nums[0]; 只有一间房肯定偷
//          dp[1] = max(nums[0], nums[1]); 两间房偷最大的

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        if(n == 2) return max(nums[0],nums[1]);
        vector<int> dp(n, 0);
        dp[0] = nums[0];
        dp[1] = max(nums[1], nums[0]);
        for(int i =2; i< n; i++) {
            dp[i] = max(dp[i-1], dp[i-2] +nums[i]);
        }
        return dp[n-1];
    }
};