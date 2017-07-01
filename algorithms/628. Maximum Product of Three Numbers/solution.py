class Solution(object):
    def maximumProduct(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        n1 = n2 = float('inf')
        m1 = m2 = m3 = float('-inf')
        for n in nums:
            if n >= m1:
                m1, m2, m3 = n, m1, m2
            elif n >= m2:
                m2, m3 = n, m2
            elif n > m3:
                m3 = n
            if n <= n1:
                n1, n2 = n, n1
            elif n < n2:
                n2 = n
        return max(n1 * n2 * m1, m1 * m2 * m3)

# 83 / 83 test cases passed.
# Status: Accepted
# Runtime: 83 ms
