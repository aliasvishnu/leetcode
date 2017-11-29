class Solution {
public:

    int findPaths(int m, int n, int N, int a, int b) {
        long dp[N+1][m+1][n+1] = {}; //set all values to zero
        long mod = 1000000007;
        if(N == 0) return dp[0][a][b];

        for(int k = 1; k <= N; k++){
            for(int i = 0; i < m; i++){
                for(int j = 0; j < n; j++){
                    dp[k][i][j] += (i-1 >= 0)? dp[k-1][i-1][j]:1;
                    dp[k][i][j] %= mod;
                    dp[k][i][j] += (i+1 < m)? dp[k-1][i+1][j]:1;
                    dp[k][i][j] %= mod;
                    dp[k][i][j] += (j-1 >= 0)? dp[k-1][i][j-1]:1;
                    dp[k][i][j] %= mod;
                    dp[k][i][j] += (j+1 < n)? dp[k-1][i][j+1]:1;
                    dp[k][i][j] %= mod;
                }
            }

        }
        return dp[N][a][b];
    }
};
