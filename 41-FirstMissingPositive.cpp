class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int len = nums.size();
        if(len == 0) return 1;

        sort(nums.begin(), nums.end());

        int answer = 0;
        for(int i = 0; i < len; i++){
            if(nums[i] < 0 || nums[i] == answer) continue;
            if(nums[i] == answer+1) answer = nums[i];
            else return answer+1;
        }

        return (nums[len-1] < 0)? 1: nums[len-1]+1;
    }
};
