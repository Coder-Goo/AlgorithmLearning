//思路：双指针：
class Solution {
public:
    vector<int> exchange(vector<int>& nums) {
        int left = 0;
        int right = nums.size()-1;
        while(left < right) {
            while(left < nums.size() && nums[left] % 2 == 1) left ++;
            while(right >= 0 && nums[right] % 2 == 0) right --;
            if(left < right) swap(nums[left],nums[right]);
            left ++;
            right --;
        }
        return nums;
    }
    
};