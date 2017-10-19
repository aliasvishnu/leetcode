class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1, amount+1);
        dp[0] = 0;
        int len = coins.size();
        for(int i = 1; i < amount+1; i++){
            for(int j = 0; j < len; j++){
                dp[i] = (i >= coins[j] && dp[i-coins[j]]+1 < dp[i])? dp[i-coins[j]]+1 : dp[i];
            }
        }

        return (dp[amount] == amount+1)? -1: dp[amount];
    }

    int coinChange2(vector<int>& coins, int amount) {
        vector<int> dp(amount+1, amount+1);

        dp[0] = 0;
        int len = coins.size();

        for(int i = 1; i < amount+1; i++){
            if(coins[0] != 0 && i % coins[0] == 0) dp[i] = i/coins[0];
        }

        for(int i = 1; i < len; i++){
            for(int j = 0; j < amount+1; j++){
                dp[j] = (j-coins[i] >= 0 && dp[j] > 1+dp[j-coins[i]])? 1+dp[j-coins[i]]: dp[j];
            }
        }

        return (dp[amount] == amount+1)? -1:dp[amount];
    }
};
