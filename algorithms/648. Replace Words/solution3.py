class Solution(object):
    def replaceWords(self, dict, sentence):
        """
        :type dict: List[str]
        :type sentence: str
        :rtype: str
        """
        d, result = set(dict), []
        for word in sentence.split():
            for i in xrange(1, len(word) + 1):
                if word[:i] in d:
                    result.append(word[:i])
                    break
            else:
                result.append(word)
        return ' '.join(result)

# 124 / 124 test cases passed.
# Status: Accepted
# Runtime: 452 ms
