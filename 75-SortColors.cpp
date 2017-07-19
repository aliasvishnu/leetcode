class Solution {
public:
    void sortColors(vector<int>& nums) {
        int len = nums.size();
        int j = 0, k = len-1;

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
