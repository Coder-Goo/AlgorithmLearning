

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size();
        if(n <=3 ) return nums[0];
        unordered_map<int, int> my_map;
        for(auto n: nums) {
            my_map[n] ++;
        }
        for(auto it = my_map.begin(); it != my_map.end(); it++) {
            if(it -> second == 1) return it -> first;

        }
        return 0;
    }
};