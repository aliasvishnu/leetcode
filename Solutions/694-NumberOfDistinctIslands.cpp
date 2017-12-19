class Solution {
public:
    unordered_set<string> st;
    int rows, cols, count = 0;

    void DFS(vector<vector<int>> &grid, int r, int c, string &s, string code){
        if(r < 0 || r >= rows) { s += ","; return;}
        if(c < 0 || c >= cols) { s += ","; return;}
        if(grid[r][c] == 0) { s += ","; return;}
        else{
            grid[r][c] = 0;
            s += code;
        }

        DFS(grid, r+1, c, s, "d");
        DFS(grid, r, c+1, s, "r");
        DFS(grid, r-1, c, s, "l");
        DFS(grid, r, c-1, s, "u");
    }

    int numDistinctIslands(vector<vector<int>>& grid) {
        rows = grid.size();
        if(rows == 0) return 0;
        cols = grid[0].size();
        if(cols == 0) return 0;

        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(grid[i][j] == 1){
                    string order = "";
                    DFS(grid, i, j, order, "s");
                    if(st.find(order) == st.end()){
                        count += 1;
                        st.insert(order);
                        // cout << order << endl;
                    }
                }
            }
        }

        return count;
    }
};
