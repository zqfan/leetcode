class Solution(object):
    def longestCommonPrefix(self, strs):
        """
        :type strs: List[str]
        :rtype: str
        """
        lcp = strs[0] if strs else ""
        while True:
            for s in strs:
                if s.find(lcp) != 0:
                    lcp = lcp[:-1]
                    break
            else:
                break
        return lcp
