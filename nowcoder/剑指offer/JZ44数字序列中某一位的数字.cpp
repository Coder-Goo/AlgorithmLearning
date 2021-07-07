// 思路：
//     1. 暴力解法
//         暴力解：从0开始逐一枚举，每枚举一个数字的时候，求出该数字的位数，并把该数字前面的所有数字的位数相加


//     2. 找规律
//         找规律：1~9一位数的9个数字，10~99的两位数组成的共180个数字，100~999组成了2700个数字  

long start;// 表示每个阶段的起始数字 1,10,100,1000
int nums;//表示每个阶段的位数
long count ;//表示每个阶段的总的数字的个数 count = 9*nums*start

//step1， 得出位数nums;
//step2,  得出位于哪个数字number
//step3,  得出位于number的第几位

class Solution {
public:
    int findNthDigit(int n) {
        //step1
        long start = 1;
        int nums = 1;
        long count = 9;
        while(n > count) {
            n -= count;
            start *= 10;
            nums ++;
            count = start * nums*9;
        }
        //step2,此时n为在位数nums的数字中还剩的 总个数， n-1/nums就能得到是第几个数字
        long number = (n-1)/nums + start; //start 为第0位数字

        //step3 （n-1）%nums就能得到位于每个数字的第几位
        string s = to_string(number);
        return s[(n-1)%nums] - '0';
    }
};