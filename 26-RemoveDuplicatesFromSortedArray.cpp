class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int len = nums.size();
        int unique = 0, prev = 0;

        if(len == 0) return 0;

        prev = nums[0];
        nums[unique] = nums[0];
        unique = 1;

        int i;
        for(i = 1; i < len; i++){
            if(nums[i] != prev){
                prev = nums[i];
                nums[unique++] = nums[i];
            }
        }
        cout << unique;

        return unique;
    }
};
