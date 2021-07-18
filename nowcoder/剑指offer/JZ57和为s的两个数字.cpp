
//输出数组里和为target的两个数字

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        int left = 0; 
        int right = n -1;
        while(left < right) {
            if(nums[left] + nums[right] > target) right --;
            else if(nums[left] + nums[right] < target) left ++;
            else {
                vector<int> res  = {nums[left], nums[right]};
                return res;
            }
        }
        return {};
    }
};