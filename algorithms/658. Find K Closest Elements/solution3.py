class Solution(object):
    def findClosestElements(self, arr, k, x):
        """
        :type arr: List[int]
        :type k: int
        :type x: int
        :rtype: List[int]
        """
        # @ cchao
        return sorted(n for d, n in sorted((abs(n - x), n) for n in arr)[:k])

# 55 / 55 test cases passed.
# Status: Accepted
# Runtime: 282 ms
