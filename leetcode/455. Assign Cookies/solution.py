class Solution(object):
    def findContentChildren(self, g, s):
        """
        :type g: List[int]
        :type s: List[int]
        :rtype: int
        """
        content = 0
        g.sort()  # use sorted in real case
        s.sort()  # ditto
        i = j = 0
        while i < len(g) and j < len(s):
            if g[i] <= s[j]:
                content += 1
                i += 1
            j += 1
        return content
