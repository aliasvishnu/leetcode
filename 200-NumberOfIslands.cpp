class Solution {
public:


    void DFS(vector<vector<char>> & grid, int rows, int cols, int i, int j){

        grid[i][j] = 0;
        // cout << "setting " << i <<"  "<< j << " as visited" << endl;

        if(i-1 >= 0 && grid[i-1][j] == '1') DFS(grid, rows, cols, i-1, j);
        if(i+1 < rows && grid[i+1][j] == '1') DFS(grid, rows, cols, i+1, j);
        if(j-1 >= 0 && grid[i][j-1] == '1') DFS(grid, rows, cols, i, j-1);
        if(j+1 < cols && grid[i][j+1] == '1') DFS(grid, rows, cols, i, j+1);
    }

    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size();
        if(rows == 0) return 0;
        int cols = grid[0].size();
        if(cols == 0) return 0;

        int count = 0;
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                // cout << i << " " << j <<endl;
                if(grid[i][j] == '1'){
                    count++;
                    DFS(grid, rows, cols, i, j);
                }
            }
        }

        return count;
    }
};
