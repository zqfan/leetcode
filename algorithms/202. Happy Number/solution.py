class Solution(object):
    def isHappy(self, n):
        """
        :type n: int
        :rtype: bool
        """
        visited = set()
        while n > 1 and n not in visited:
            visited.add(n)
            n = sum(int(d) ** 2 for d in str(n))
        return n == 1

# 401 / 401 test cases passed.
# Status: Accepted
# Runtime: 62 ms
# beats 35.12%
