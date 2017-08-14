#include <unordered_map>
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map;
        int len = nums.size();
        vector<int> answer;
        for(int i = 0; i < len; i++){
            if(map.find(target-nums[i]) != map.end()){
                answer.push_back(map[target-nums[i]]);
                answer.push_back(i);
            }

            map[nums[i]] = i;

        }

        return answer;
    }
};
