// NOTE: THEY ASKED FOR INDEX TRIPLETS, MEANING THE TRIPLETS NEED NOT BE UNIQUE
class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int maintarget) {
        int len = nums.size();
        long answer = 0;

        sort(nums.begin(), nums.end());
        int i = 2;
        while(i < len){
            int front = 0, target = maintarget-nums[i], cur1 = -nums[i];

            int back = i-1;
            while(front < back){
                long sum = nums[front]+nums[back];

                if(sum < target){
                    answer += (back-front);
                    front++;
                }else back--;
            }
            i++;
        }
        return answer;
    }
};
