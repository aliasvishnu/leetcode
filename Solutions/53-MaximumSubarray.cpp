#include <algorithm>

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max_so_far = nums[0];
        int len = nums.size();

        // what if all the numbers are less than 0.
        for(int i = 0; i < len; i++){
            if(nums[i] > max_so_far) max_so_far = nums[i];
        }

        // if all the numbers are less than 0, max_so_far will be less than 0.
        if(max_so_far < 0) return max_so_far;

        int cur_tot = 0;
        for(int i = 0; i < len; i++){
            cur_tot = max(0, cur_tot+nums[i]);
            if(cur_tot > max_so_far){
                max_so_far = cur_tot;
            }
        }


        return max_so_far;
    }
};
