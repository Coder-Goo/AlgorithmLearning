
排序数组中找到一个缺失的数字！！

思路： 如果缺少一个数字，那么缺少的那部分的个数一定少！！
如果nums[i] != i; 那么这一段肯定是少的

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0] == 1? 0: 1; 
        int left = 0, right = n -1, mid = 0;
        while(left <=  right) {
            mid = left + ((right - left) >> 1);
            if(nums[mid] == mid) left = mid + 1;
            else right = mid -1;
        }
        return left;
    }
};