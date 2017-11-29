class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int lislen = 1, liscount = 1, len = nums.size();
        vector<int> L(len, 0);
        vector<int> C(len, 1);
        if(len == 0) return 0;

        L[0] = 1;
        for(int i = 1; i < len; i++){
            L[i] = 1;
            for(int j = i-1; j >= 0; j--){
                if(nums[j] < nums[i]){
                    if(L[i] < 1+L[j]){
                        L[i] = 1+L[j];
                        C[i] = C[j];
                    }else if(L[i] == 1+L[j])
                        C[i] += C[j];
                }
            }

            if(L[i] == lislen) liscount += C[i];
            else if(L[i] > lislen){
                lislen = L[i];
                liscount = C[i];
            }else continue;
        }

        return liscount;
    }
};
