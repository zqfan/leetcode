class Solution(object):
    def partition(self, s):
        """
        :type s: str
        :rtype: List[List[str]]
        """
        if not s:
            return []
        res = [[s]] if s == s[::-1] else []
        for i in xrange(1, len(s)):
            ss = s[:i]
            if ss != ss[::-1]:
                continue
            for p in self.partition(s[i:]):
                res.append([ss] + p)
        return res
