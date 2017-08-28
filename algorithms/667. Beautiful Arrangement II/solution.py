class Solution(object):
    def constructArray(self, n, k):
        """
        :type n: int
        :type k: int
        :rtype: List[int]
        """
        res, l, r = [], 1, k + 1
        while l < r:
            res.append(l)
            l += 1
            res.append(r)
            r -= 1
        if l == r:
            res.append(l)
        return res + range(k + 2, n + 1)

# 68 / 68 test cases passed.
# Status: Accepted
# Runtime: 102 ms
