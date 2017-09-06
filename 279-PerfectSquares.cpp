class Solution {
public:

    int calc(int n){
        static unordered_map<int, int> dp;
        dp[0] = 0;
        if(dp.find(n) != dp.end()) return dp[n];
        else{
            int min = n+1;
            for(int i = 1; i*i <= n; i++){
                int val = calc(n-i*i)+1;
                if(val < min) min = val;
            }
            dp[n] = min;
            return min;
        }
    }

    int numSquares(int n) {
        return calc(n);
    }
};
