class Solution {
public:
    int max(int a, int b){
        return (a>b)?a:b;
    }

    int rob(vector<int>& nums) {
        unordered_map<int, int> dp;

        int len = nums.size();
        if(len == 0) return 0;
        if(len == 1) return nums[0];
        if(len == 2) return max(nums[1], nums[0]);
        if(len == 3) return max(nums[1], nums[2]+nums[0]);

        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        dp[2] = max(nums[1], nums[2]+nums[0]);

        for(int i = 3; i < len; i++){
            dp[i] = max(dp[i-3], dp[i-2]) + nums[i];
        }
        int maxval = 0;
        for(int i = 0; i < len; i++){
            if(maxval < dp[i]) maxval = dp[i];
        }

        return maxval;
    }
};
