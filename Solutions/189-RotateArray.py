class Solution(object):
    def rotate(self, nums, k):
        nums[:] = nums[::-1]
        nums[:k] = nums[k-1::-1]
        nums[k:] = nums[-1:k-1:-1]
        
