class Solution(object):
    def singleNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        s = 0
        for i in range(32):
            bitcount = 0
            for n in nums:
                bitcount += n & 1<<i
            if bitcount % 3:
                s += 1<<i
        # python negative uses twos-completment numbers
        if s & (1<<31):
            return s - (1<<32)
        else:
            return s
