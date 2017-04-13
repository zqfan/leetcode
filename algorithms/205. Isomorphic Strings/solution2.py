class Solution(object):
    def isIsomorphic(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: bool
        """
        chr_map = {}
        chr_map_rev = {}
        for i, c in enumerate(s):
            chr_map.setdefault(c, t[i])
            chr_map_rev.setdefault(t[i], c)
            if chr_map[c] != t[i]:
                return False
            if chr_map_rev.get(t[i], c) != c:
                return False
        return True
