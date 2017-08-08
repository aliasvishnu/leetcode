class Solution {
public:
    int checkRow(vector<vector<char>> &board, int row){
        unordered_set<char> st;

        for(int j = 0; j < 9; j++){
            if(st.find(board[row][j]) != st.end()) return 0;
            else if(board[row][j] != '.') st.insert(board[row][j]);
        }
        return 1;
    }

    int checkCol(vector<vector<char>> &board, int col){
        unordered_set<char> st;

        for(int i = 0; i < 9; i++){
            if(st.find(board[i][col]) != st.end()) return 0;
            else if(board[i][col] != '.') st.insert(board[i][col]);
        }
        return 1;
    }

    int checkBox(vector<vector<char>> &board, int r, int c){
        unordered_set<char> st;

        for(int i = r; i < r+3; i++){
            for(int j = c; j < c+3; j++){
                if(st.find(board[i][j]) != st.end()) return 0;
                else if(board[i][j] != '.') st.insert(board[i][j]);
            }
        }
        return 1;
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        int flag = 1;
        for(int i = 0; i < 9; i++){
            flag *= checkRow(board, i);
            flag *= checkCol(board, i);
        }

        cout << flag << endl;
        for(int i = 0; i < 9; i+=3){
            for(int j = 0; j < 9; j+=3){
                flag *= checkBox(board, i, j);
            }
        }

        return flag;

    }
};
