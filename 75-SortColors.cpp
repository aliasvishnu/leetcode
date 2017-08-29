class Solution {
public:
    void sortColors(vector<int>& nums) {
        int len = nums.size();
        int j = 0, k = len-1;

        // i is where 0 should go, and k is where 2 should go, but as long as 2 in not there in k, i = k could be filled by 0 as well.
        for(int i = 0; i <= k; i++){
            if(nums[i] == 0){
                int temp = nums[i];
                nums[i] = nums[j];
                nums[j++] = temp;
            }else if(nums[i] == 2){
                int temp = nums[i];
                nums[i--] = nums[k];
                nums[k--] = temp;
            }
        }
    }
};
