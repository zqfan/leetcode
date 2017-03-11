class Solution(object):
    def nextGreaterElement(self, findNums, nums):
        """
        :type findNums: List[int]
        :type nums: List[int]
        :rtype: List[int]
        """
        next_greater_map = {}
        for i, n in enumerate(nums):
            for j in xrange(i+1, len(nums)):
                if nums[j] > n:
                    next_greater_map[n] = nums[j]
                    break
            else:
                next_greater_map[n] = -1
        return map(next_greater_map.get, findNums)

# 17 / 17 test cases passed.
# Status: Accepted
# Runtime: 49 ms
# 97.53%
