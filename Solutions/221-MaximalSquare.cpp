class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if(matrix.size() == 0) return 0;

        vector<vector<int>> dp(matrix.size(), vector<int> (matrix[0].size(), 0));

        int rows = matrix.size(), cols = matrix[0].size();
        long maxval = 0;

        for(int i = 0; i < rows; i++){
            dp[i][0] = (matrix[i][0] == '1')?1:0;
            if(dp[i][0]) maxval = 1;
        }
        for(int j = 0; j < cols; j++){
            dp[0][j] = (matrix[0][j] == '1')?1:0;
            if(dp[0][j]) maxval = 1;
        }

        for(int i = 1; i < rows; i++){
            for(int j = 1; j < cols; j++){
                if(matrix[i][j] == '1'){
                    dp[i][j] = 1+ min(min(dp[i-1][j-1], dp[i-1][j]), dp[i][j-1]);

                    if(dp[i][j]*dp[i][j] > maxval) maxval = dp[i][j]*dp[i][j];
                }

            }
        }

        return maxval;

    }
};
