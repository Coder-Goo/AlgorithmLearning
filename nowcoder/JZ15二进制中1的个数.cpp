
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        while(n) {
            if(n & 1) count ++;
            n= n>>1;
        }
        return count;
    }
};

//上面的解法如果输入的数是负数，则导致无限循环
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        unsigned int flag = 1;
        while(flag) {
            if(n & flag) count ++;
            flag = flag << 1;
        }
        return count;
    }
};