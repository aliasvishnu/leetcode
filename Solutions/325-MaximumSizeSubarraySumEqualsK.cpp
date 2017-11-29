class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int maxLen = 0, curSum = 0; // count measures how many more 0's than 1's
        int len = nums.size();
        for(int i = 0; i < len; i++){
            int num = nums[i];

            curSum += num;

            if(curSum == k) if(i+1 > maxLen) maxLen = i+1;

            if(mp.find(curSum-k) != mp.end()) if(i-mp[curSum-k] > maxLen) maxLen = i-mp[curSum-k];

            if(mp.find(curSum) == mp.end()){
                cout << curSum << " " << i << endl;
                mp[curSum] = i;
            }
        }

        return maxLen;
    }
};
