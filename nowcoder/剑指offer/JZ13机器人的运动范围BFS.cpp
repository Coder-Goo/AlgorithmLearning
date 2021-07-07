/* 
 *  思路： 广度优先BFS
 *  广度优先是靠队列来实现的，队列为空，表示可以到达的格子已经遍历结束
 *  先将开始结点压入队列，
 *  开始遍历，弹出队首元素，判断队首元素是否合格，合格的话，count+1，visited标记，并将当前结点的右结点和下方结点入队列
 *  如果不合格，继续下一次遍历，
 */

class Solution {
public:
    int movingCount(int m, int n, int k) {
        queue<vector<int>>que;
        int result = 0;
        que.push({0,0});
        vector<vector<bool>>visited(m,vector(n,false));
        while(!que.empty()) {
            vector<int> temp(que.front());
            que.pop();
            int i = temp[0], j = temp[1];
            if(i<0 || i>=m || j<0 || j>= n || OverK(i,j,k) || visited[i][j]) continue;
            else {
                visited[i][j] = true;
                result ++;
                que.push({i+1, j});
                que.push({i,j+1});
            }
        }
        return result;
    }

private:
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
