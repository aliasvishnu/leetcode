class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        vector<int> temp;
        temp.push_back(0);
        int len = nums.size(), prev = 0;

        for(int i = 0; i < len; i++){
            temp.push_back(nums[i]+prev);
            prev += nums[i];
        }

        long start = 0, end = 1, maxLen = INT_MAX;
        while(start < end && end < len+1){
            if(temp[end]-temp[start]  < s){
                end++;
            }else if(temp[end]-temp[start] >= s){
                if(maxLen > end-start){
                    maxLen = end-start;
                }
                start++;
            }
        }

        if(maxLen == INT_MAX) return 0;
        return maxLen;
    }
};
