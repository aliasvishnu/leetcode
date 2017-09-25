// Idea - DP
// Bottom up solution presented here,
// Time - O(len*target)
// Space - O(target)
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        unordered_map<int, int> dp;
        int len = nums.size();

        for(int i = 0; i <= target; i++){
            dp[i] = 0;

            for(int j = 0; j < len; j++){
                if(i-nums[j] > 0) dp[i] += dp[i-nums[j]];
                if(i == nums[j]) dp[i] += 1;
            }
        }

        return (dp.find(target) == dp.end())?0:dp[target];
    }
};
