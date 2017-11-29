class Solution {
public:
    int threeSumClosest(vector<int>& nums, int maintarget) {
        int len = nums.size(), minerror = INT_MAX;
        vector<int> answer;

        sort(nums.begin(), nums.end());
        int i = 2;
        while(i < len){
            int front = 0, target = maintarget-nums[i], cur1 = -nums[i];

            while(i < len && nums[i]+cur1 == 0) i++;
            i--;

            int back = i-1;
            while(front < back){
                int sum = nums[front]+nums[back];
                vector<int> temp;

                if(abs(sum-target) < minerror){
                    minerror = abs(sum-target);
                    temp.push_back(nums[front]);
                    temp.push_back(nums[back]);
                    temp.push_back(nums[i]);
                    answer = temp;
                }

                if(sum <= target){
                    int cur = nums[front];
                    while(front < back && nums[front] == cur) front++;
                }else if(sum > target){
                    int cur = nums[back];
                    while(front < back && nums[back] == cur) back--;
                }
            }
            i++;
        }
        return answer[0]+answer[1]+answer[2];
    }
};
