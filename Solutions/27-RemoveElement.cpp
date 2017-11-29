class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int len = nums.size();
        int count = 0;
        int i = 0;

        if(len == 0) return 0;

        while(i < len){
            if(nums[i] == val)
                count += 1;
            else nums[i-count] = nums[i];
            i += 1;
        }
        cout << "Count = " << count;
        return len-count;
    }
};
