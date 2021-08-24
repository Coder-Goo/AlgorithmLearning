深度优先 + 广度优先

leetcode 200 求岛屿的数量   ：找到1组成的岛屿的数量

输入：grid = [
  ["1","1","1","1","0"],
  ["1","1","0","1","0"],
  ["1","1","0","0","0"],
  ["0","0","0","0","0"]
]
输出：1

这种求图的邻域问题，使用深度优先效果害挺好！

```cpp
class Solution {
public:
    //将访问过的1和相邻的1都变为'V'
    void DFS(int x, int y, vector<vector<char>>& grid, int m , int n) {
        if(x < 0 || x >= m || y< 0 || y>= n || grid[x][y] == 'V' || grid[x][y] == '0') return;

        grid[x][y] = 'V';

        //四个方向搜索
        DFS(x+1, y, grid, m, n);
        DFS(x -1, y, grid, m, n);
        DFS(x, y+1, grid, m, n);
        DFS(x, y-1, grid, m, n);
    }

    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        if( m== 0) return 0;
        int n = grid[0].size();
        if(n ==  0) return 0;

        int res = 0;
        vector<vector<char>>copy(grid);
        for(int i = 0; i< m; i++) {
            for(int j = 0; j< n; j++) {
                if(copy[i][j] == '1') {
                    DFS(i, j, copy, m, n);
                    res++;
                }
            }
        }
        return res;
    }
};


广度优先：

