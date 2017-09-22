class Solution(object):
    def subsetsWithDup(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """

        nums = sorted(nums)
        answer = []
        l = len(nums)
        if l == 0:
            return []
        if l == 1:
            return [[nums[0]]];

        i = 0

        while(i < l):
            result = self.subsetsWithDup(nums[i+1:])

            for r in result:
                answer.append([nums[i]] + r)
            answer.append([])

            cur = nums[i]
            while (i < l and cur == nums[i]):
                i += 1


        return answer
