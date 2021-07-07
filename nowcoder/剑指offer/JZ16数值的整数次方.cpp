//递归方法
class Solution {
public:
    double myPow(double x, int n) {
        if(n == 0) return 1.0;
        else if(n < 0) return 1 / (x * myPow(x, - (n + 1)));  //这里的加1就很灵性了，被-2147483648恰好变为正数正好超过int边界
        else if(n&1) return x * myPow(x * x, n /2);
        else return myPow(x * x, n / 2);
    }
};


//迭代方法
// x^n = (x^2)^n/2 = ((x^2)^2)^n/4...
//所以可以 x=x*x 且 n=n/2进入下一次迭代 则x= x*x, n= n/2;
//如果有奇数，x^11=x* (x^2)^5 = x*  ((x^2)^2)^2 * x^2
//递归方法
class Solution {
public:
    double myPow(double x, int n) {
        long p = n;
        bool flag = false;
        if( n < 0) {
            p = -p;
            flag = true;
        }
        double res = 1;
        while(p) {
            if(p&1) res *= x;
            x = x*x;
            p = p>>1;
        }
        if(flag) return 1/res;
        else return res;
    }
};