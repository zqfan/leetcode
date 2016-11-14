class Solution(object):
    def findMaximumXOR(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        # refer: https://discuss.leetcode.com/topic/63299/python-6-lines-bit-by-bit
        # suppose we already know max xor num bits from 31...i,
        # how to get i-1 bit? we get all prefix set 31...i-1 of nums,
        # suppose max xor comes from x and y, then
        # max_xor ^ y = x ^ y ^ y = x, so we can suppose max xor
        # bit i-1 is 1, and let it do xor with every element of
        # prefix set, if the result is still in prefix set, then
        # bit i-1 is 1, else is 0
        max_xor = 0
        for i in reversed(range(32)):
            max_xor <<= 1
            prefix = {n>>i for n in nums}
            max_xor += any(max_xor^1^p in prefix for p in prefix)
        return max_xor
