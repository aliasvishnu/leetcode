class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int num1 = -1, num2 = -1, count1 = 0, count2 = 0;
        int len = nums.size();
        vector<int> answer;
        if(len== 0) return answer;

        for(int i = 0; i < len; i++){
            if(nums[i] == num1){
                count1 += 1;
            }else if(nums[i] == num2){
                count2 += 1;
            }else if(count1 == 0){
                num1 = nums[i];
                count1 = 1;
            }else if(count2 == 0){
                num2 = nums[i];
                count2 = 1;
            }else{
                count1 -= 1;
                count2 -= 1;
            }
        }

        count1 = 0;
        count2 = 0;

        for(int i = 0; i < len; i++){
            if(nums[i] == num1) count1++;
            if(nums[i] == num2) count2++;
        }

        if(count1 > len/3) answer.push_back(num1);
        if(count2 > len/3) answer.push_back(num2);
        return answer;
    }
};
