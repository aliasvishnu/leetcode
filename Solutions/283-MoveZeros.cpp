// Time - O(n)
// Space - O(1)
// Main idea - two pointers
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int zpos = 0, len = nums.size(), nonzpos = 0;

        while(nonzpos < len && zpos < len){
            swap(nums[nonzpos], nums[zpos]);
            while(zpos < len && nums[zpos] != 0) zpos++;
            while(nonzpos < len && (nums[nonzpos] == 0 || nonzpos < zpos)) nonzpos++;
        }
    }
};
