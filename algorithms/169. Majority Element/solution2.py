class Solution(object):
    def majorityElement(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        count = 0
        for n in nums:
            if count == 0:
                major = n
                count = 1
            elif n == major:
                count += 1
            else:
                count -= 1
        return major

# 44 / 44 test cases passed.
# Status: Accepted
# Runtime: 62 ms
