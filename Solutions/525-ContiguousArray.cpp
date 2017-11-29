class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> mp;
        int count = 0, maxLen = 0; // count measures how many more 0's than 1's
        int len = nums.size();
        for(int i = 0; i < len; i++){
            int num = nums[i];

            if(num == 0) count++;
            else count--;

            if(count == 0) if(i+1 > maxLen) maxLen = i+1;  // if ever the total is zero, then check [0 to i]

            if(mp.find(count) != mp.end()) if(i-mp[count]+1 > maxLen)  maxLen = i-mp[count];

            if(mp.find(count) == mp.end()){
                mp[count] = i;
            }
        }

        return maxLen;
    }
};
