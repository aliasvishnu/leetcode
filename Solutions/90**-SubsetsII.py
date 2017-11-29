# Idea - build from empty set to the answer, [[], [1]] + [2] -> [[], [1], [2], [1, 2]] + [2] = [[], [1]] + {[[2], [1, 2]]+[2]}
class Solution(object):
    def subsetsWithDup(self, nums):
        nums.sort()
        answer = [[]]
        for i in range(len(nums)):
            if i == 0 or nums[i] != nums[i-1]:
                l = len(answer)

            for j in range(len(answer)-l, len(answer)):
                answer.append(answer[j] + [nums[i]])

        return answer
