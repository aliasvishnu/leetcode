class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int len = nums.size();
        vector<int> answer;

        for(int i = 0; i < len; i++){
            int val = ((nums[i]<0)?-1:1)*nums[i];
            val -= 1;
            if(nums[val] > 0) nums[val] *= -1;
        }

        for(int i = 0; i < len; i++){
            if(nums[i] > 0) answer.push_back(i+1);
        }

        return answer;
    }
};
