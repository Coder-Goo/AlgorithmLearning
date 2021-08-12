用最少的箭去射爆气球


//暴力法：先按右顶点排序，然后射出每支箭，同时判断哪些气球被射穿

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int n = points.size();
        if(n < 1) return 0;
        vector<bool> flags(n, false);  //判断气球有没有被射穿，she'chu'a'g
        sort(points.begin(), points.end(), [](vector<int>& vec1, vector<int>& vec2) {return vec1[1]< vec2[1];});
        int ans = 0;
            for(int i = 0; i< n; i++) {
                if(!flags[i]) {
                    flags[i] = true;
                    ans ++;
                    for(int j = i+1; j<n; j++) {
                        if(!flags[j] && points[j][0] <= points[i][1]) {
                            flags[j] = true;
                        }
                    }
                }  
            } 
        return ans;
    }
};



//排序+贪心
//按右边界排序
//那么右边界的最小值b就是射出的第一只箭的位置，  那么后面的区间的左边界如果大于b,那么就是下一个射箭的区间
// class Solution {
// public:
//     int findMinArrowShots(vector<vector<int>>& points) {
//         int n = points.size();
//         if(n < 1) return 0;
//         if(n < 2) return 1;
//         sort(points.begin(),points.end(), [](vector<int>& vec1, vector<int>& vec2){ return vec1[1] < vec2[1];} );
//         int position = points[0][1];
//         int ans = 1;
//         for(auto& p:points) {
//             if(p[0] > position) {
//                 position = p[1];
//                 ans ++;
//             }
//         }
//         return ans;
//     }
// };

