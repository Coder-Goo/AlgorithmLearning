

输入一个正整数 target ，输出所有和为 target 的连续正整数序列（至少含有两个数）。

序列内的数字由小到大排列，不同序列按照首个数字从小到大排列。

 

示例 1：

输入：target = 9
输出：[[2,3,4],[4,5]]
示例 2：

输入：target = 15
输出：[[1,2,3,4,5],[4,5,6],[7,8]]

//暴力解法：
class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) {
        int limit = (target + 1)/ 2;
        vector<vector<int>> res;
        vector<int> vec;
        int sum = 0;
        for(int i = 1; i< limit; i++) {
            for(int j = i; j < target; j ++) {
                sum += j;
                if(sum > target) {
                    sum = 0;
                    break;
                } else if(sum == target){
                    vec.clear();
                    for(int k = i; k<= j; k++) {
                        vec.emplace_back(k);
                    }
                    res.emplace_back(vec);
                    sum = 0;
                    break;
                }
            }
        }
        return res;
    }
};

//滑动窗口

class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) {
       int limit = (target + 1)/2;
       int sum = 0;
       int left = 1;
       int right = 0;
       vector<int> vec;
       vector<vector<int>>res;
           while(right <= limit) {
               right ++;
               sum += right;
               while(sum >= target ) {
                   if(sum == target) {
                       for(int k = left; k<= right; k++) {
                           vec.emplace_back(k);
                       }    
                       res.emplace_back(vec);
                       vec.clear();
                        break;
                   } else {
                       sum -= left;
                       left++;
                   }
               }
           }
           return res;
    }
};