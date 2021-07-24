
看力扣官方题解：有视频的



class Solution {
public:
    vector<int> singleNumbers(vector<int>& nums) {
        int res = 0; 
        for(auto n: nums) res ^= n;
        //找到第一个为1的那个位置，表示在这个为，两个数是不同的
        int index = 1;
        while((res & index)==0) {
            index <<= 1;
        }
        int a = 0, b= 0;
        for(auto n : nums) {
            if(n& index) a^= n;
            else b^= n;
        }
        return {a,b};
    }
};