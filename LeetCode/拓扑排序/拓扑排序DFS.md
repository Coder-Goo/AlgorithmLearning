

```cpp
class Solution {
    vector<vector<int>> edges;
    vector<int> visited;
    bool valid = true;

    vector<int>result;

public:
    //深度遍历每个未访问的结点，遇到正在访问的，说明存在环，直接返回， 否则一直访问到底部，
    //visited有三种状态：0：未访问，1：正在访问， 2：访问完毕

    //DFS这里还写了个递归终止条件，其实可以不写的，因为没有出度的时候，for循环也不会执行
    void DFS(int i) {
        if(edges[i].size() ==0 ) { //没有出度，说明已经到底了
            visited[i] = 2;
            result.push_back(i);
            return;
        }

        //当前结点正在访问
        visited[i] = 1;
        //遍历所有出度，遇到未访问的之间递归访问
        for(int out: edges[i]) {
            if(visited[out] == 1) { //找到了环，直接退出，不用再搜索了
                valid = true;
                return;
            }
            else if(visited[out] == 0) { //还未被访问，
                DFS(out);
            }
        }
        visited[i] =2;
        result.push_back(i);
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        edges.resize(numCourses);
        visited.resize(numCourses);
        //建立有向图
        for(auto p: prerequisites) {
            int pre = p[1];
            int cur = p[0];
            edges[pre].push_back(cur);
        }
        for(int i = 0; i < numCourses && valid; i++) {
            if(visited[i] == 0) {
                DFS(i);
            }
        }
        if(!valid) return false;
        return result.size() == numCourses;
    }
};
```