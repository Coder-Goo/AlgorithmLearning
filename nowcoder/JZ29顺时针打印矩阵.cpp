#include<vector>
using namespace std;

/*
    思路：
    1. 方法一：回字型打印left, right, top , bottom; 进一层的话left+1, right -1; top -1; bottom-1
    2. 方法二：每步走n-1步；下一层就是n-3步，只适用于方阵。
*/
class Solution {
public:
    vector<int> printMatrix(vector<vector<int>> matrix) {
        int m = matrix.size();
        if(m < 1) return {}; 
        int n = matrix[0].size();
        if(n < 1) return {};
        vector<int> result;
        int left = 0, right = n -1, top = 0, bottom = m -1;
        while(left <= right && top <= bottom) {
            for(int i= left; i<= right; i++) {
                result.push_back(matrix[top][i]);
            }
            for(int i = top +1; i<= bottom; i++) {
                result.push_back(matrix[i][right]);
            }
            
            //只有一行或一列的时候保证只打印一次，避免重复打印
             if(left != right && top!= bottom) {
                for(int i = right -1; i>= left; i--) {
                    result.push_back(matrix[bottom][i]);
                }
                for(int i = bottom -1; i> top; i--) {
                    result.push_back(matrix[i][left]);
                }
            }
            
            left ++;
            right --;
            top ++;
            bottom --;
        }
        return result;
    }
};