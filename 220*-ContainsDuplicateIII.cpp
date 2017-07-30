class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        if(t < 0 || k < 0) return false;
        unordered_map<long, int> mp;
        int len = nums.size();
        for(int i = 0; i < len; i++){
            long val = long(nums[i])-INT_MIN;
            val = val/((long)t+1);
            if(mp.find(val) != mp.end() && abs(mp[val]-i) <= k && (abs((long)nums[i]-(long)nums[mp[val]]) <= t)) return true;
            if(mp.find(val-1) != mp.end() && abs(mp[val-1]-i) <= k && (abs((long)nums[i]-(long)nums[mp[val-1]]) <= t)) return true;
            if(mp.find(val+1) != mp.end() && abs(mp[val+1]-i) <= k && (abs((long)nums[i]-(long)nums[mp[val+1]]) <= t)) return true;
            mp[val] = i;
        }

        return false;
    }
};
