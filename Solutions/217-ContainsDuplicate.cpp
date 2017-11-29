class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> s;
        int len = nums.size();

        if(len <= 1) return false;

        for(int i = 0; i < nums.size(); i++){
            if(s.find(nums[i]) != s.end()) return true;
            else s.insert(nums[i]);
        }

        return false;
    }
};
