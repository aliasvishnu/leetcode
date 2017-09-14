class Solution {
public:
    void sortColors(vector<int>& nums) {
        int len = nums.size();
        int j = 0, k = len-1;

        // j is where 0 should go, and k is where 2 should go, but as long as 2 in not there in k, i = k could be filled by 0 as well.
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

// SAME SOLUTION, BUT CLEANER

// class Solution {
// public:
//     void sortColors(vector<int>& nums) {
//         int j = 0, k = nums.size()-1;
//
//         for(int i = 0; i <= k; i++){
//             if(nums[i] == 0) swap(nums[j++], nums[i]);
//             if(nums[i] == 2) swap(nums[k--], nums[i--]);
//         }
//     }
// };
