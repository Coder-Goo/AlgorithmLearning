//按左节点排序，后面的左端点小于当前右端点的都要合并

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end(), [](vector<int>&vec1, vector<int>&vec2){return vec1[0] < vec2[0];});
        vector<vector<int>>res;
        
        for(int i = 0; i<n; i++) {
            int pos = intervals[i][1];
            int start = intervals[i][0];
            int j = i + 1;
            while( j< n && intervals[j][0] <= pos) {
                pos = max(pos,intervals[j][1]);
                j++;
            }
            i = j-1;
            res.push_back({start, pos});
        }
        return res;
    }
};