/*
思路： 深度优先，
1. 沿着上下左右中的一个方向走，如朝上走，到下一个格子，判断格子是否符合要求（边界，<=k，未被访问过），符合结果+1，并进入下一层，
不符合返回上一层
 
 //这一题注意DFS里的return 1+ DFS + DFS+ DFS+DFS;  这个1+很有灵性
 */

class Solution {
public:
    int movingCount(int m, int n, int k) {
        count = 0;
        vector<vector<bool>>visited(m,vector<bool>(n, false));
        return DFS(0,0,m,n,k,visited);
    }

private:
    int count;
//深度优先搜索，每一层遍历都 +1
    int DFS(int i, int j, int m, int n, int k , vector<vector<bool>>&visited) {
        if(i<0 || i>= m || j < 0 || j>= n || OverK(i, j,k) || visited[i][j]) return 0;
        visited[i][j] = true;
        return 1+ DFS(i+1,j,m,n,k,visited) + DFS(i-1,j,m,n,k,visited) + DFS(i,j+1,m,n,k,visited) + DFS(i,j-1,m,n,k,visited);
    }

//判断是否超过k
    bool OverK(int i, int j, const int k) {
        int sum = 0; 
        while(i) {
            sum += i%10;
            i = i/10;
        }
        while(j) {
            sum += j%10;
            j = j/10;
        }
        if(sum > k) return true;
        else return false;
    } 
};