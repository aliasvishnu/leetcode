class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> s;
        int len = nums.size();

        if(len <= 1) return false;

        for(int i = 0; i < nums.size(); i++){
            if(s.find(nums[i]) == s.end()) s[nums[i]] = i;
            else{
                if(abs(i-s[nums[i]]) <= k) return true;
                else s[nums[i]] = i;
            }
        }

        return false;
    }
};
