class Solution(object):
    def findLongestWord(self, s, d):
        """
        :type s: str
        :type d: List[str]
        :rtype: str
        """
        longest_word = ''
        maxlen = 0
        for word in d:
            i = j = 0
            while i < len(word) and j < len(s):
                if word[i] == s[j]:
                    i += 1
                j += 1
            if i == len(word) and i >= maxlen:
                if i == maxlen:
                    longest_word = min(longest_word, word)
                else:
                    longest_word = word
                maxlen = i
        return longest_word
