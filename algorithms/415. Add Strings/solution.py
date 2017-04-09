class Solution(object):
    def addStrings(self, num1, num2):
        """
        :type num1: str
        :type num2: str
        :rtype: str
        """
        result = []
        carry = 0
        i = len(num1) - 1
        j = len(num2) - 1
        while i >= 0 or j >= 0 or carry:
            s = carry
            if i >= 0:
                s += ord(num1[i]) - ord('0')
                i -= 1
            if j >= 0:
                s += ord(num2[j]) - ord('0')
                j -= 1
            result.append(str(s % 10));
            carry = s / 10
        return ''.join(reversed(result))

# 315 / 315 test cases passed.
# Status: Accepted
# Runtime: 75 ms
# beats 74.73%
