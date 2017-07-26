class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 1;
        int len = digits.size();

        for(int i = len-1; i >= 0; i--){
            int temp = (carry+digits[i])/10;
            digits[i] = (carry+digits[i])%10;
            carry = temp;
        }

        if(carry != 0) digits.insert(digits.begin(), carry);
        return digits;

    }
};
