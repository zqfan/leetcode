class Solution(object):
    def thirdMax(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        m1 = m2 = m3 = None
        for n in nums:
            if n > m1:
                m1, m2, m3 = n, m1, m2
            elif m1 > n > m2:
                m2, m3 = n, m2
            elif m2 > n > m3:
                m3 = n
        return m3 if m3 is not None else m1

# 26 / 26 test cases passed.
# Status: Accepted
# Runtime: 65 ms
# beats 20.52%
