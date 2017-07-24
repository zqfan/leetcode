class Solution(object):
    def findErrorNums(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        n = len(nums)
        expect = n * (n + 1) / 2
        actual = sum(nums)
        cnt = [0] * (n + 1)
        for n in nums:
            if cnt[n]:
                return [n, expect - actual + n]
            cnt[n] += 1
