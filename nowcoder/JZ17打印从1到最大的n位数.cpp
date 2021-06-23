/*
    n位的最大数是10^n -1;
    那遍历输出就行
*/

class Solution {
public:
    vector<int> printNumbers(int n) {
         int max= pow(10,n) -1;
         vector<int>result;
         for(int i = 1; i<= max; i++) {
             result.push_back(i);
         }
         return result;
    }
};

/*
    如果考虑比较大的数，不管什么类型都会越界的
    可以使用字符串来拼接得到每个数
    思路：有n位数，从高位开始，每一位都是从0~9中选一个，再从0~9中选一个拼接在后面，就是DFS
    n      n-1   n-2   ...    1    0
    0~9   0~9   0~9    ...   0~9  0~9
    但是还要去除前面的0，如01要变成1
*/
class Solution {
public:
    vector<int> printNumbers(int n) {
         
    }
    void DFS(int k) {
        if()
    }
};
