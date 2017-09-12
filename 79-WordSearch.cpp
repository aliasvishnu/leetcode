// Time - O(mn)
// Space - O(1)
// Main idea - DFS

class Solution {
public:
    // vector<vector<bool>> mark;
    int rows, cols;
    bool DFS(vector<vector<char>>& M, int r, int c, int pos, int len, string &s){
        if(pos == len) return true;
        if(r < 0 || r >= rows || c < 0 || c >= cols) return false;
        if(M[r][c] != s[pos] || M[r][c] == '#') return false;

        char bkp = M[r][c];
        M[r][c] = '#';

        bool e = false;
        if(DFS(M, r+1, c, pos+1, len, s) || DFS(M, r, c+1, pos+1, len, s)
           || DFS(M, r-1, c, pos+1, len, s) || DFS(M, r, c-1, pos+1, len, s)) e = true;

        M[r][c] = bkp;

        return e;
    }

    bool exist(vector<vector<char>>& board, string word) {
        rows = board.size();
        cols = board[0].size();
        int len = word.size();
        if(len == 0) return false;

        bool e = false;
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
               if(DFS(board, i, j, 0, len, word)) return true;
            }
        }
        return false;
    }
};
