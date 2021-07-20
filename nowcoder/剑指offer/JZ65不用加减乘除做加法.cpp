
十进制的加法其实是按二进制来的，
那么二进制0+0,1+0,0+1都不会产生进位，只有1+1才会产生进位，
那么先异或一波就是0+0,1+0,0+1的值，
1+1的值可以先做与运算，然后右移，即可

一直循环，直到没有进位

class Solution {
public:

    int add(int a, int b) {
        do {
            int sum = a ^ b;
            int array =(unsigned int)(a & b)<<1;  //c++中负数不支持右移，因为结果是不定的
            a = sum;
            b = array;
        } while(array != 0);
    }
};