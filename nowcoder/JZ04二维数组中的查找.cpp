#include<vector>
using namespace std;


//判断右上角的元素
//1. 如果小于右上角的元素，那么最后一列不用看
//2. 如果大于右上角元素，那么第一行不用看

class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        if(n == 0) return false;
        int m = matrix[0].size(); 
        if(m == 0) return false;
        int i = 0 , j = m - 1;
        while(i < n && j >= 0) {
            if(target ==  matrix[i][j]) {
                return true;
            } else if(target > matrix[i][j]) i++;
            else j--;
        }
        return false;
    }
};