#define vvi vector<vector<int>>
class Solution {
public:
    bool insideBounds(int i, int j, int rows, int cols){
        return (i < rows && i >= 0) && (j < cols && j >= 0);
    }

    int DFS(vvi &matrix, int i, int j, int depth, vvi &DP, vvi &visit, int rows, int cols){
        int maxDepth = depth;
        if(DP[i][j] != -1) return depth+DP[i][j];
        visit[i][j] = 1;


        if(insideBounds(i+1, j, rows, cols) && visit[i+1][j] == 0 && matrix[i+1][j] > matrix[i][j]){
           int d = (DP[i+1][j] == -1)? DFS(matrix, i+1, j, depth+1, DP, visit, rows, cols): depth+DP[i+1][j];
           maxDepth = max(maxDepth, d);
        }
        if(insideBounds(i, j+1, rows, cols) && visit[i][j+1] == 0 && matrix[i][j+1] > matrix[i][j]){
           int d =  (DP[i][j+1] == -1)? DFS(matrix, i, j+1, depth+1, DP, visit, rows, cols): depth+DP[i][j+1];
           maxDepth = max(maxDepth, d);
        }
        if(insideBounds(i-1, j, rows, cols) && visit[i-1][j] == 0 && matrix[i-1][j] > matrix[i][j]){
           int d =  (DP[i-1][j] == -1)? DFS(matrix, i-1, j, depth+1, DP, visit, rows, cols): depth+DP[i-1][j];
           maxDepth = max(maxDepth, d);
        }
        if(insideBounds(i, j-1, rows, cols) && visit[i][j-1] == 0 && matrix[i][j-1] > matrix[i][j]){
           int d =  (DP[i][j-1] == -1)? DFS(matrix, i, j-1, depth+1, DP, visit, rows, cols): depth+DP[i][j-1];
           maxDepth = max(maxDepth, d);
        }

        visit[i][j] = 0;
        DP[i][j] = max(maxDepth, depth) - depth + 1;
        return max(maxDepth, depth);
    }

    int longestIncreasingPath(vvi& matrix) {
        int rows = matrix.size();
        if(rows == 0) return 0;
        int cols = matrix[0].size();

        vvi DP (rows, vector<int> (cols, -1));
        vvi visit  (rows, vector<int> (cols, 0));
        int maxLen = -1;
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(DP[i][j] == -1){
                    DP[i][j] = DFS(matrix, i, j, 1, DP, visit, rows, cols);
                }

                if(DP[i][j] > maxLen) maxLen = DP[i][j];
            }
        }

        return maxLen;
    }
};
