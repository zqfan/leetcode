class Solution(object):
    def getMaxRepetitions(self, s1, n1, s2, n2):
        """
        :type s1: str
        :type n1: int
        :type s2: str
        :type n2: int
        :rtype: int
        """
        if set(s2) - set(s1):
            return 0
        dp = {}
        l1 = len(s1); l2 = len(s2)
        i1 = j1 = i2 = j2 = 0
        while i1 < n1 * l1:
            j2 = i2 % l2
            while s1[i1%l1] != s2[j2]:
                i1 += 1
            if i1 >= n1 * l1:
                break
            j1 = i1 % l1
            k = (j1, j2)
            if k not in dp:
                dp[k] = (i1, i2)
            else:
                pre_i1, pre_i2 = dp[k]
                repeat = (n1*l1 - i1) / (i1 - pre_i1)
                i1 += repeat * (i1 - pre_i1)
                i2 += repeat * (i2 - pre_i2)
            if i1 < n1 * l1:
                i1 += 1
                i2 += 1
        return i2 / (n2 * l2)

# 34 / 34 test cases passed.
# Status: Accepted
# Runtime: 72 ms
