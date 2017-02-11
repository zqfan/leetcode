class Solution(object):
    def nextGreaterElement(self, findNums, nums):
        """
        :type findNums: List[int]
        :type nums: List[int]
        :rtype: List[int]
        """
        # @yuxiangmusic
        desc_stack = []
        next_greater_map = {}
        for n in nums:
            while desc_stack and desc_stack[-1] < n:
                next_greater_map[desc_stack.pop()] = n
            desc_stack.append(n)
        return map(lambda x: next_greater_map.get(x, -1), findNums)

# 17 / 17 test cases passed.
# Status: Accepted
# Runtime: 52 ms
# 93.64%
