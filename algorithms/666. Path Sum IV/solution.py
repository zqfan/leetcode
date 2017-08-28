class Solution(object):
    def pathSum(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        s = collections.defaultdict(int)
        l = collections.defaultdict(int)
        for n in nums[::-1]:
            r, c, v = n / 100, n / 10 % 10, n % 10
            l[r, c] = max(1, l[r + 1, c * 2] + l[r + 1, c * 2 - 1])
            s[r, c] = s[r + 1, c * 2] + s[r + 1, c * 2 - 1] + l[r, c] * v
        return s[1, 1]

# 195 / 195 test cases passed.
# Status: Accepted
# Runtime: 46 ms
