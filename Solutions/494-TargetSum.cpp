class Solution {
public:

    unordered_map<int, unordered_map<int, int>> dp;
    int findTargetSumWays(vector<int> &nums, int start, int S){
        int len = nums.size();
        if(nums.size() == start) return (S == 0)*1;

        if(dp.find(start+1) == dp.end() || dp[start+1].find(S+nums[start]) == dp[start+1].end()){
            dp[start+1][S+nums[start]] = findTargetSumWays(nums, start+1, S+nums[start]);
        }

        if(dp.find(start+1) == dp.end() || dp[start+1].find(S-nums[start]) == dp[start+1].end()){
            dp[start+1][S-nums[start]] = findTargetSumWays(nums, start+1, S-nums[start]);
        }

        return dp[start+1][S-nums[start]] + dp[start+1][S+nums[start]];
    }

    int findTargetSumWays(vector<int>& nums, int S) {
        return findTargetSumWays(nums, 0, S);
    }
};
