class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int len = nums.size();
        long lim = pow(2, len);
        vector<vector<int>> ans;


        for(long i = 0; i < lim; i++){
            int num = i, j = 0;
            vector<int> temp;
            while(num != 0){
                if(num%2) {
                    temp.push_back(nums[j]);
                }
                num /= 2;
                j++;
            }

            ans.push_back(temp);

        }

        return ans;
    }
};
