class Solution(object):
    def magicalString(self, n):
        """
        :type n: int
        :rtype: int
        """
        l = [1, 2, 2]
        i = 2
        while len(l) < n:
            l.append(3-l[-1])
            if l[i] == 2:
                l.append(l[-1])
            i += 1
        while len(l) > n:
            l.pop()
        return l.count(1)

# 65 / 65 test cases passed.
# Status: Accepted
# Runtime: 145 ms
# 94.62%
