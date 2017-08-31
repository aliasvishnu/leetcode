class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> answer;

        int len = nums.size(), start = 0, end = 0;
        if(len == 0) return answer;

        int i = 0;
        while(i < len){
            // cout << i << endl;
            start = i, end = i;
            i++;

            while(i < len){
                if(nums[i] - nums[end] == 1){
                    end++; i++;
                }else break;
            }

            if(start < end) answer.push_back(to_string(nums[start]) + "->" + to_string(nums[end]));
            else answer.push_back(to_string(nums[start]));
        }

        return answer;
    }
};
