
从扑克牌中抽5张牌，判断是不是顺子

先排序：

//牌之间的差别< 大小王的个数就可以连成顺子

class Solution {
public:
    bool isStraight(vector<int>& nums) {
        sort(nums.begin(), nums.end());   //时间复杂度
        if(nums[0] != 0) {
            for(int i = 1; i<5; i++) {
                if(nums[i] - nums[i-1] != 1) return false;
            } 
        }
        else {
            int zero_count = 1;
            int i = 1;
            for(; i<5; i++) {
                if(nums[i] != 0) break;
                else {
                    zero_count ++;
                }
            }
            int diff = 0;
            for(int j = i+1; j<5; j++) {
                if(nums[j] == nums[j-1]) return false;
                diff += nums[j] - nums[j-1];
            }
            diff -= (4-i);
            if(zero_count < diff) return false;
        }
        return true;
    }
};