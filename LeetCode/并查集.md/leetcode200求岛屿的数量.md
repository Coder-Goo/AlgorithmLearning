
leetcode 200题

给你一个由 '1'（陆地）和 '0'（水）组成的的二维网格，请你计算网格中岛屿的数量。
岛屿总是被水包围，并且每座岛屿只能由水平方向和/或竖直方向上相邻的陆地连接形成。
此外，你可以假设该网格的四条边均被水包围

输入：grid = [
  ["1","1","1","1","0"],
  ["1","1","0","1","0"],
  ["1","1","0","0","0"],
  ["0","0","0","0","0"]
]
输出：1

//将4个方向相连的岛屿认为是一个集合

```cpp

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        if(m ==0) return 0;
        int n = grid[0].size(); 
        if(n == 0) return 0;

        parent.resize(m*n);
        res = 0;
        //初始化自己的父亲，并且初始化岛屿的数量
        for(int i = 0; i< m; i++) {
            for(int j = 0; j< n; j++) {
                if(grid[i][j] == '1') {
                    parent[i*n +j] = i*n +j;
                    res ++;                          //记录初始集合的数量，后面 合并的时候再减少
                }
            }
        }
        //开始合并并计算岛屿的数量
        for(int i= 0; i<m; i++) {
            for(int j = 0; j< n; j++) {
                if(grid[i][j] == '1') {

                    //四个方向合并
                    if(i -1 >= 0 && grid[i-1][j] == '1') Union(i*n+j, (i-1)*n +j);
                    if(i +1 < m && grid[i+1][j] == '1') Union(i*n+j, (i+1)*n +j);
                    if(j -1 >= 0 && grid[i][j-1] == '1') Union(i*n+j, i*n +j-1);
                    if(j +1 < n && grid[i][j+1] == '1') Union(i*n+j, i*n +j+1);
                }
            }
        }
        return res;
    }

private:
    vector<int> parent;
    int res;
    //查
    int Find(int x) {
        int r = x;
        while(r != parent[r]) {
            r = parent[r];
        }
        return r;
    }
    //并： 合并后，岛屿的数量要减少
    void Union(int x, int y) {
        int px = Find(x), py = Find(y);
        if(px != py) {
            parent[px] = py;
            res --;                //每次合并都将减少一个集合
        }
    }
};