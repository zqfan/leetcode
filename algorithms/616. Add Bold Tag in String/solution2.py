class Solution(object):
    def addBoldTag(self, s, dict):
        """
        :type s: str
        :type dict: List[str]
        :rtype: str
        """
        n = len(s)
        bold, dict = [0] * (len(s) + 2), sorted(dict, key=len, reverse=1)
        for i in xrange(len(s)):
            for w in dict:
                if s.find(w, i) == i:
                    bold[i+1:i+1+len(w)] = [1] * len(w)
                    break
        t = ''
        for i in xrange(1, len(s) + 1):
            if not bold[i-1] and bold[i]:
                t += "<b>"
            t += s[i-1]
            if bold[i] and not bold[i+1]:
                t += "</b>"
        return t

# 70 / 70 test cases passed.
# Status: Accepted
# Runtime: 906 ms
