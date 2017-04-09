class Solution(object):
    def addStrings(self, num1, num2):
        """
        :type num1: str
        :type num2: str
        :rtype: str
        """
        # @dalwise
        z = itertools.izip_longest(num1[::-1], num2[::-1], fillvalue='0')
        result, carry, ord02 = [], 0, ord('0') * 2
        for a, b in z:
            s = ord(a) + ord(b) - ord02 + carry
            result.append(str(s % 10))
            carry = s // 10
        total = ''.join(result[::-1])
        return '1' + total if carry else total

# 315 / 315 test cases passed.
# Status: Accepted
# Runtime: 62 ms
# beats 87.04%
