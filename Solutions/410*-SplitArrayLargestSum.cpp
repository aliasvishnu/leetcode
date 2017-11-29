class Solution {
public:

    bool canSplit(vector<int> nums, int val, int cuts){
        int i = 0, len = nums.size(), curSum = 0;
        for(int num: nums){
            if(curSum+num > val){
                cuts--;
                curSum = num;
            }else{
                curSum += num;
            }

            if(cuts < 0) return false;
        }


        return true;
    }

    int splitArray(vector<int>& nums, int m) {
        int start = 0, end = 0, len = nums.size();

        for(int i = 0; i < len; i++){
            if(start < nums[i]) start = nums[i];
            end += nums[i];
        }

        int mid = 0;
        while(start < end){
            cout << start << "  " << end << endl;
            mid = start + (end-start)/2;

            if(canSplit(nums, mid, m-1)) end = mid;
            else start = mid+1;
        }

        return start;
    }
};
