class Solution {
public:
    int dp[21][21] = {0};
    int DP(vector<int> &nums, int start, int end){
        if(start == end) return nums[start];

        if(dp[start+1][end] == -3000) dp[start+1][end] = DP(nums, start+1, end);
        if(dp[start][end] == -3000) dp[start][end-1] = DP(nums, start, end-1);

        int a = nums[start] - dp[start+1][end];
        int b = nums[end] - dp[start][end-1];

        return (a>b)?a:b;
    }

    bool PredictTheWinner(vector<int>& nums) {
        for(int i = 0; i < 21; i++){
            for(int j = 0; j < 21; j++){
                dp[i][j] = -3000; // Set a number as replacement for NULL
            }
        }
        int len = nums.size();
        dp[0][len-1] = DP(nums, 0, len-1);
        if(dp[0][len-1] >= 0) return true;
        else return false;
    }
};
