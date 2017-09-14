class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int len = nums.size();
        int minLen = len+1;
        bool found = false;
        if (len == 0) return 0;

        int sum = nums[0];
        int start = 0, end = 0;
        while(start <= end && end < len){
            if(sum < s){
                end += 1;
                sum += nums[end];
            }
            else if(sum >= s){
                found = true;
                cout << "Sum reached more that S" << end-start+1 <<  endl;
                if(minLen > (end-start+1)) minLen = end-start+1;
                sum -= nums[start];
                start += 1;
            }
        }

        return (found)?minLen:0;
    }
};
