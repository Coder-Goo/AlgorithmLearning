
//思路： 深度优先(回溯)
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        rows = board.size();
        cols = board[0].size();
        n = word.size();
        for(int i = 0; i< rows; i++ ) {
            for(int j = 0; j< cols; j++) {
                if(DFS(board, word, i,j,0)) return true;
            }
        }
        return false;
    }

private:
    int rows, cols, n;
    bool DFS(vector<vector<char>>& board, string & word, int i,int j,int k) {
        if(i>=rows || i<0 || j>=cols || j<0 ||k>= n|| board[i][j] != word[k]) return false;
        if(k == n -1) return true;
        board[i][j] = '\0';   //做标记，表示已经被访问
        bool ret = DFS(board, word, i+1,j,k+1) ||DFS(board, word, i-1,j,k+1) 
        ||DFS(board, word, i,j+1,k+1)||DFS(board, word, i,j-1,k+1);
        board[i][j] = word[k]; //回溯撤销标记
        return ret;
    }
};