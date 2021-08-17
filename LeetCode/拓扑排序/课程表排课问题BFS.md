详见leetcode 207题

BFS: 广度优先：
先将无入度的结点入队列，表示已经访问，然后更新每个结点的入度信息，再将入度为0的结点入队列，直到所有队列为空，

如果里面有环，那么队列为空时，并没有访问完全：
```cpp
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> nodes(numCourses);              //存储的是入度数
        vector<vector<int>>edges(numCourses);       //存储的是 边
        for(auto edge: prerequisites) {
            int cur = edge[0];
            int pre = edge[1];
            edges[pre].push_back(cur);
            nodes[cur] ++;                     //每增加一个入度，就加1
        }

        //将入度为0的结点入队列
        queue<int> q;
        for(int i= 0; i< nodes.size(); i++) {
            if(nodes[i] == 0)
            q.push(i);
        }
        vector<int> visited;
        
        //存在环时，队列是空的，而出度还没全部清零
        while(!q.empty()) {
            int finish = q.front();
            q.pop();
            visited.push_back(finish);
            for(int f: edges[finish]) {
                nodes[f]--;
                if(nodes[f] == 0) q.push(f);
            }
        }
        return visited.size() == numCourses;
    }
};

```