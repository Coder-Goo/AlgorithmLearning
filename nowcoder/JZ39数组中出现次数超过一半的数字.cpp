//方法一：排序后，取中间的数

//方法二： 摩尔投票法：将众数记为+1,其他数记为-1
//维护一个candidate和count，遍历数组，如果出现candidate，那么count+1； 没有出现，那么count-1；
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate = -1;
        int count = 0; 
        for(auto num: nums) {
            if(num == candidate) {
                count ++;
            } else if( --count < 0) {
                candidate = num;
                count = 1;
            }
        }
        return candidate;
    }
};