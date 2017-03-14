class Solution(object):
    def palindromePairs(self, words):
        """
        :type words: List[str]
        :rtype: List[List[int]]
        """
        d = {w:i for i, w in enumerate(words)}
        r = []
        for i, w in enumerate(words):
            for j in xrange(len(w)+1):
                wj, wk = w[:j], w[j:]
                rwj, rwk = wj[::-1], wk[::-1]
                if j and wj == rwj and rwk in d and d[rwk] != i:
                    r.append([d[rwk], i])
                if wk == rwk and rwj in d and d[rwj] != i:
                    r.append([i, d[rwj]])
        return r
