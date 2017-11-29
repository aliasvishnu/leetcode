class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int len = nums.size();
        vector<int> ret (nums);
        if(len <= 1) return nums;

        int left = 1;

        for(int i = 0; i < len; i++){
            ret[i] = left;
            left *= nums[i];
        }

        int right = 1;
        for(int i = len-1; i >= 0; i--){
            ret[i] *= right;
            right *= nums[i];
        }


        return ret;
    }
};
