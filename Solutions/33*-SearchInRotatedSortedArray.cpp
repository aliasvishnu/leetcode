class Solution {
public:
    int search(vector<int>& nums, int target) {
        int start = 0, end = nums.size()-1;
        if(end == -1) return -1;

        while(start <= end){
            int mid = (end-start)/2+start;
            if(nums[mid] == target) return mid;

            if(nums[mid] >= nums[start]){
                if(nums[start] <= target && nums[mid] > target){
                    end = mid-1;
                }else
                    start = mid+1;
            }

            else if(nums[mid] <= nums[end]){
                if(nums[end] >= target && nums[mid] < target){
                    start = mid+1;
                }else
                    end = mid-1;
            }
        }

        return -1;
    }
};
