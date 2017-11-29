class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        vector<int> left;
        vector<int> right;
        int len = nums.size();
        int mid = len/2;

        for(int i = 0; i < len; i++){
            if(i == mid) continue;
            if(nums[i] >= nums[mid]) left.push_back(nums[i]);
            if(nums[i] < nums[mid]) right.push_back(nums[i]);
        }

        if(left.size() == k-1) return nums[mid];
        else if (left.size() >= k) return findKthLargest(left, k);
        else return findKthLargest(right, k-left.size()-1);

    }
};
