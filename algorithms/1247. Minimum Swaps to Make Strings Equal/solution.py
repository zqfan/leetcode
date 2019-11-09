class Solution(object):
    def minimumSwap(self, s1, s2):
        """
        :type s1: str
        :type s2: str
        :rtype: int
        """
        xy, yx = 0, 0
        for i, _ in enumerate(s1):
            xy += s1[i] == 'x' and s2[i] == 'y'
            yx += s1[i] == 'y' and s2[i] == 'x'
        if xy % 2 != yx % 2:
            return -1
        return xy / 2 + yx / 2 + xy % 2 + yx % 2
