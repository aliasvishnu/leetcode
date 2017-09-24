// Idea - Build solution from LSB to MSB
// O(n*32) - O(n) time complexity
// O(1) space complexity
class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int len = nums.size(), k = 0, m = 0, count = 0, l = 32;

        for(int l = 0; l < 32; l++){

            for(int i = 0; i < len; i++){
                if(nums[i] % 2) k++;
                else m++;

                nums[i] = nums[i]>>1;
            }
            count += k*m;
            k = 0; m = 0;
        }

        return count;
    }
};
