
class Solution{
    int search(vector<int> nums, int target) {
        int n = nums.size();
        if(n < 1) return 0;
        int left = 0; int right = n -1;
        int mid = 0;
        while(left <= right) {
            mid = left + ((right - left) >> 1);
            if(nums[mid] <= target) left = mid +1;  //找到target的最右边的下标
            else right = mid -1;
        }
        int right_index = right;
        if(right > 0 && nums[right] != target) return 0;
        int left = 0;
        while( left <= right )  {
            mid = left + ((right - left) >> 1);
            if(nums[mid] < target) left = mid +1;
            else right = mid - 1;
        }
        int left_index = right;

        return right_index - left_index -1;

    }
};