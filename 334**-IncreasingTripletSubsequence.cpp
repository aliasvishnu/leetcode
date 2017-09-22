class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        vector<bool> next(nums.size(), false);
        int a = INT_MAX, b = INT_MAX;
        for(int num: nums){
            if(num <= a) a = num;
            else if(num <= b) b = num;
            else return true;
        }
        return false;
    }
};
