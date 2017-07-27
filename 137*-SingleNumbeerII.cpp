class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int bitCount[32] = {0};
        int len = nums.size();
        for(int i = 0; i < len; i++){
            int temp = nums[i];

            for(int i = 0; i < 32; i++){
                int hasBit = 0;
                if((temp&(1<<i))!= 0) hasBit = 1;
                if(hasBit) bitCount[i] = (bitCount[i]+1)%3;
            }
        }

        int answer = 0;
        for(int i = 0; i < 32; i++){
            if(bitCount[i] > 0) answer |= (1<<i);
        }

        return answer;
    }
};
