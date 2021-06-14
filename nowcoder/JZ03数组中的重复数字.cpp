 //思路：使用集合记录数字是否出现过，
 #include<set>
 #include <vector>

 using namespace std;


class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        set<int>my_set;
        for(int i = 0; i< nums.size(); i++) {
            if(my_set.find(nums[i]) != my_set.end()) {
                return nums[i];
            } else my_set.insert({nums[i]});
        }
        return -1;
    }
};

