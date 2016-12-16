class Solution(object):
    def findMaxForm(self, strs, m, n):
        """
        :type strs: List[str]
        :type m: int
        :type n: int
        :rtype: int
        """
        maxcount = {(m,n): 0}
        for s in strs:
            count0 = s.count('0')
            count1 = len(s) - count0
            for (remain0, remain1), count in maxcount.items():
                if remain0 >= count0 and remain1 >= count1:
                    key = (remain0-count0, remain1-count1)
                    if key not in maxcount or maxcount[key] <= count:
                        maxcount[key] = count + 1
        return max(maxcount.itervalues())

# 60 / 60 test cases passed.
# Status: Accepted
# Runtime: 695 ms
