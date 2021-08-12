
求删除的最少的区间数量，使得区间互不重叠
和求最多无重复区间数量是一样的

//求删除的最少的区间数量，那就是求最多有多少个无重复的区间
//使用动态规划！
//dp[i]表示以第i个区间结尾的可以组成的最多的无重复区间数
//那么如果区间j的右端点小于i个左端点，表示二者无重复，则dp[i] = dp[j]+1;

class Solution {
public:
    static bool cmp(vector<int>&vec1, vector<int>& vec2) {   //这里必须声明为静态函数，因为非静态函数要通过对象才能调用，
                                                            //这里没有对象，所以不能调用
        if(vec1[0]== vec2[0]) return vec1[1]<vec2[1];
        else return vec1[0] < vec2[0];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end(), cmp);
        vector<int>dp(n, 1);
        int num= 0;
        for(int i = 0; i< n; i++) {
            for(int j = 0; j<i; j++) {
                if(intervals[j][1] <= intervals[i][0]) {
                    dp[i] = max(dp[i],dp[j]+1);
                    
                } 
            }
            num = max(num, dp[i]);
        }
        return n- num;
    }
};

//上面的时间复杂度太高

使用贪心算法
按右端点排序，那么最小的右端点就第一个区间，左端点就不关键，剩下的区间们就构成子问题，
在剩下的找到最小的右端点且不与第一个区间相交就是第二个区间，以此类推
class Solution {
public:
    static bool cmp(vector<int>&vec1, vector<int>& vec2) {   //这里必须声明为静态函数，因为
        return vec1[1]<vec2[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        if(n < 1) return 0;
        sort(intervals.begin(), intervals.end(), cmp);
        int num = 1;
        int pos = intervals[0][1];
        for(int i = 1; i< n; i++) {
            if(intervals[i][0] >= pos) {
                num++;
                pos = intervals[i][1];
            }
        }
        return n -num;
    }
};
