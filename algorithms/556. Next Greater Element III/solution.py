class Solution(object):
    def nextGreaterElement(self, n):
        """
        :type n: int
        :rtype: int
        """
        digits = list(str(n))
        l = len(digits)
        for i in xrange(l - 1, 0, -1):
            if digits[i - 1] < digits[i]:
                right = sorted(digits[i:])
                p = bisect.bisect(right, digits[i - 1])
                digits[i - 1], right[p] = right[p], digits[i - 1]
                r = int(''.join(digits[:i] + right))
                return r if r < 0x7fffffff else -1
        return -1

# 34 / 34 test cases passed.
# Status: Accepted
# Runtime: 35 ms
