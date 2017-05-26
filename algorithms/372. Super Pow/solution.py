class Solution(object):
    def superPow(self, a, b):
        """
        :type a: int
        :type b: List[int]
        :rtype: int
        """
        s = 1
        for d in b:
            s = pow(s, 10, 1337) * pow(a, d, 1337) % 1337
        return s

# 54 / 54 test cases passed.
# Status: Accepted
# Runtime: 72 ms
# beats 81.95 %
