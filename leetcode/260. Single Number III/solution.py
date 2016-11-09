class Solution(object):
    def singleNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        xor = 0
        for n in nums:
            xor ^= n
        k = 0
        for i in range(32):
            k = 1<<i
            if xor & k:
                break
        n1 = n2 = 0
        for n in nums:
            if n & k:
                n1 ^= n
            else:
                n2 ^= n
        return [n1, n2]
