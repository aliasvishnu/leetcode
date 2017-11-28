
/*
Find the location closest from the end which has segment ab of the form a < b, and make it ba.
Then sort the number from from b onwards.
*/
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int len = nums.size();
        int flag = 0;
        for(int i = 0; i < len-1; i++){
            if(nums[i+1] > nums[i]) flag = 1;
        }
        if(flag == 0) sort(nums.begin(), nums.end());
        else{
            for(int i = len-1; i > 0 ; i--){
                if(nums[i] > nums[i-1]){
                    int index = i;
                    for(int k = i; k < len; k++){
                        if(nums[k] < nums[index] && nums[k] > nums[i-1]) index = k;
                    }
                    int temp = nums[i-1];
                    nums[i-1] = nums[index];
                    nums[index] = temp;
                    sort(nums.begin()+i, nums.end());
                    break;
                }
            }
        }
    }
};
