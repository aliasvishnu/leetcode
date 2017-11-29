class Solution {
public:

    vector<vector<int>> threeSum(vector<int>& nums) {
        int len = nums.size();
        vector<vector<int>> answer;

        sort(nums.begin(), nums.end());
        int i = 2;
        while(i < len){
            int front = 0;
            int target = -nums[i];
            while(i < len && nums[i]+target == 0) i++;
            i--;
            int back = i-1;
            while(front < back){
                int sum = nums[front]+nums[back];
                if(sum == target){
                    vector<int> temp = {nums[front], nums[back], nums[i]};
                    answer.push_back(temp);

                    while(front < back && nums[front] == temp[0]) front++;
                    while(front < back && nums[back] == temp[1]) back--;
                }else if(sum < target) front++;
                else if(sum > target) back--;
            }
            i++;
        }
        return answer;
    }
};
