class Solution(object):
    def findRepeatedDnaSequences(self, s):
        """
        :type s: str
        :rtype: List[str]
        """
        res = set()
        slices = set()
        for i in xrange(len(s)-9):
            ss = s[i:i+10]
            if ss in slices:
                res.add(ss)
            else:
                slices.add(ss)
        return list(res)
