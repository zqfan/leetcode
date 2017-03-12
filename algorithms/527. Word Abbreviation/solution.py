class Solution(object):
    def wordsAbbreviation(self, dict):
        """
        :type dict: List[str]
        :rtype: List[str]
        """
        def start(s1, s2):
            if len(s1) != len(s2) or s1[0] != s2[0] or s1[-1] != s2[-1]:
                return 1
            for i in xrange(len(s1)):
                if s1[i] != s2[i]:
                    return i + 1

        res = [0] * len(dict)
        d = sorted(zip(dict, xrange(len(dict))),
                   key=lambda s: (len(s[0]), s[0][0], s[0][-1], s[0]))
        for i, (word, idx) in enumerate(d):
            s = 1
            if i > 0:
                s = max(s, start(d[i-1][0], word))
            if i < len(d) - 1:
                s = max(s, start(d[i+1][0], word))
            if len(word) < 4 or s >= len(word) - 2:
                res[idx] = word
            else:
                res[idx] = word[:s] + str(len(word)-s-1) + word[-1]
        return res
