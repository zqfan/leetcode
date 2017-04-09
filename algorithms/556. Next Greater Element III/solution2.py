class Solution(object):
    def nextGreaterElement(self, n):
        """
        :type n: int
        :rtype: int
        """
        digits = list(str(n))
        stack = []
        for i in xrange(len(digits)-1, 0, -1):
            stack.append(i)
            if digits[i] > digits[i-1]:
                while stack and digits[stack[-1]] > digits[i-1]:
                    j = stack.pop()
                digits[j], digits[i-1] = digits[i-1], digits[j]
                r = int(''.join(digits[:i] + sorted(digits[i:])))
                return r if r <= 0x7fffffff else -1
        return -1

# 34 / 34 test cases passed.
# Status: Accepted
# Runtime: 42 ms
