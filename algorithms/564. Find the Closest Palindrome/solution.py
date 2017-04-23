class Solution(object):
    def nearestPalindromic(self, n):
        """
        :type n: str
        :rtype: str
        """
        # based on @awice and @o_sharp
        l = len(n)
        # with different digits width, it must be either 10...01 or 9...9
        candidates = set((str(10 ** l + 1), str(10 ** (l - 1) - 1)))
        # the closest must be in middle digit +1, 0, -1, then flip left to right
        prefix = int(n[:(l + 1)/2])
        for i in map(str, (prefix - 1, prefix, prefix + 1)):
            candidates.add(i + [i, i[:-1]][l & 1][::-1])
        candidates.discard(n)
        return min(candidates, key=lambda x: (abs(int(x) - int(n)), int(x)))
