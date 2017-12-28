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

        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);

        for(int i = 2; i < len; i++){
            dp[i] = max(dp[i-2] + nums[i], dp[i-1]);
        }


        return dp[len-1];
    }
};
