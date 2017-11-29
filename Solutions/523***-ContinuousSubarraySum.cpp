class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int sum = 0; bool nonzero = false;
        unordered_set<int> st;
        // if( k < 0) k *= 1;

        if(k == 0){
            for(int i = 0; i < nums.size()-1; i++) if(nums[i] == 0 && nums[i+1] == 0) return true;
            return false;
        }

        for(int num: nums){
            if(num != 0) nonzero = true;

            sum = (sum%k + num%k) % k;
            cout << sum << endl;
            if(st.find(sum) != st.end()) return true;
            st.insert(sum);
        }

        if(!nonzero) return false;

        sum = 0;
        for(int num: nums) sum = (sum%k + num%k) %k;

        if(sum == 0 && nums.size() >= 2) return true;
        return false;
    }
};
