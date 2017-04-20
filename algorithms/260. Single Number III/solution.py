class Solution(object):
    def singleNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        x = reduce(operator.xor, nums)
        # get last set bit, which is a diff bit for n1 and n2
        x &= -x
        n1 = n2 = 0
        for n in nums:
            if n & x:
                n1 ^= n
            else:
                n2 ^= n
        return [n1, n2]
