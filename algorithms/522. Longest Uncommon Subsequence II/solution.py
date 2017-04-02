class Solution(object):
    def findLUSlength(self, strs):
        """
        :type strs: List[str]
        :rtype: int
        """
        def is_subseq(s1, s2):
            '''s1 is subsequence of s2'''
            i = 0
            for c in s2:
                if i < len(s1) and c == s1[i]:
                    i += 1
            return i == len(s1)

        strs = sorted(strs, key=len, reverse=1)
        for i in xrange(len(strs)):
            for j in xrange(len(strs)):
                if i != j and is_subseq(strs[i], strs[j]):
                    break
            else:
                return len(strs[i])
        return -1
