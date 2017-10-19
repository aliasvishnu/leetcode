class Solution {
public:

    int change(int amount, vector<int>& coins) {
        vector<int> dp(amount+1, -1);
        if(amount == 0) return 1;
        if(coins.size() == 0) return 0;

        dp[0] = 1;
        int len = coins.size();

        for(int i = 1; i < amount+1; i++){
            if(coins[0] != 0 && i % coins[0] == 0) dp[i] = 1;
        }

        for(int i = 1; i < len; i++){
            for(int j = 0; j < amount+1; j++){
                int offset = (j-coins[i] >= 0 && dp[j-coins[i]] != -1)? dp[j-coins[i]]: 0;

                if(dp[j] == -1 && offset != 0) dp[j] = offset;
                else if(dp[j] != -1 && offset != 0) dp[j] += offset;
            }
        }

        return (dp[amount] == -1)? 0:dp[amount];
    }
};
