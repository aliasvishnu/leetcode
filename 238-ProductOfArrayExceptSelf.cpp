class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int len = nums.size();

        vector<int> forward(len, 1);
        vector<int> backward(len, 1);

        forward[0] = 1;
        for(int i = 1; i < len; i++){
            // cout << "Here";
            forward[i] = forward[i-1]*nums[i-1];

        }

        backward[len-1] = 1;
        for(int i = len-2; i >= 0; i--){
            backward[i] = backward[i+1]*nums[i+1];
        }

        vector<int> answer(len, 1);
        for(int i = 0; i < len; i++){
            answer[i] = forward[i]*backward[i];
        }

        return answer;
    }
};
