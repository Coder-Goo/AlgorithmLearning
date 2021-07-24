
//输入一个数组A，构建一个数组B，B中每一个元素B[i]都是A中除了A[i]之外的所有元素的乘积
看力扣题解，把数组分为上三角和下三角！

class Solution {
public:
    vector<int> constructArr(vector<int>& a) {
        int n = a.size();
        if(n <= 1) return {};
        vector<int>B(n);
        B[0] = 1;
        int temp = 1;
        for(int i = 1; i< n; i++) {
            B[i] = B[i-1]* a[i-1];
        }
        for(int j = n-2; j>= 0; j--) {
            temp *= a[j+1];  
            B[j] *= temp ;
        }
        return B;
    }
};