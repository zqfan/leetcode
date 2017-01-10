class Solution(object):
    def findComplement(self, num):
        """
        :type num: int
        :rtype: int
        """
        # @Ipeq1
        i = 1
        while i <= num:
            i <<= 1
        return (i - 1) ^ num

# 149 / 149 test cases passed.
# Status: Accepted
# Runtime: 35 ms
# 97.10% 
