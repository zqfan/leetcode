class Solution(object):
    def permuteUnique(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        res = [[]]
        for n in nums:
            newres = []
            for p in res:
                for i in xrange(len(p) + 1):
                    newres.append(p[:i] + [n] + p[i:])
                    if i < len(p) and p[i] == n:
                        break
            res = newres
        return res

# 30 / 30 test cases passed.
# Status: Accepted
# Runtime: 119 ms
# 58.90 %
