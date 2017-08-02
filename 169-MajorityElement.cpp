class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int len = nums.size();
        vector<int> answer;
        unordered_map<int, int> mp;

        for(int i= 0; i < len; i++){
            mp[nums[i]]++;
        }

        unordered_map<int, int> ::iterator it;
        for(it = mp.begin(); it != mp.end(); it++){
            if(it->second > len/2){
                return it->first;
            }
        }
        return -1;
    }
};
