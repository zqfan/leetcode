class Solution(object):
    def replaceWords(self, dict, sentence):
        """
        :type dict: List[str]
        :type sentence: str
        :rtype: str
        """
        t = {}
        for word in dict:
            cur = t
            for c in word:
                cur = cur.setdefault(c, {})
            cur['$'] = word
        senwords = sentence.split()
        for i in xrange(len(senwords)):
            word = senwords[i]
            cur = t
            for c in word:
                cur = cur.get(c)
                if not cur:
                    break
                if '$' in cur:
                    senwords[i] = cur['$']
                    break
        return ' '.join(senwords)

# 124 / 124 test cases passed.
# Status: Accepted
# Runtime: 128 ms
