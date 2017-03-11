class Solution(object):
    def findAllConcatenatedWordsInADict(self, words):
        """
        :type words: List[str]
        :rtype: List[str]
        """
        words.sort(key=len)
        result = []
        words_set = set()
        for word in words:
            dp = [False] * (len(word)+1)
            dp[0] = True
            for i in xrange(1, len(dp)):
                for j in xrange(i):
                    if dp[j] and word[j:i] in words_set:
                        dp[i] = True
                        break
            if dp[-1] and word:
                result.append(word)
            words_set.add(word)
        return result
