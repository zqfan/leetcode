class Solution(object):
    def replaceWords(self, dict, sentence):
        """
        :type dict: List[str]
        :type sentence: str
        :rtype: str
        """
        hashmap = {}
        for word in dict:
            h, cur, base = 0, 1, 26
            for c in word:
                h += (ord(c) - 96) * cur
                cur *= base
            hashmap[h] = word
        result = sentence.split()
        for i in xrange(len(result)):
            h, cur, base = 0, 1, 26
            for c in result[i]:
                h += (ord(c) - 96) * cur
                if h in hashmap:
                    result[i] = hashmap[h]
                    break
                cur *= base
        return ' '.join(result)

# 124 / 124 test cases passed.
# Status: Accepted
# Runtime: 555 ms
