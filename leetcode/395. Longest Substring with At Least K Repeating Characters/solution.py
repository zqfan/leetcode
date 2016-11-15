class Solution(object):
    def longestSubstring(self, s, k):
        """
        :type s: str
        :type k: int
        :rtype: int
        """
        maxlen = 0
        counter = collections.defaultdict(int)
        i = 0
        while i + k < len(s):
            counter.clear()
            mask = 0; idx = i
            for j in range(i, len(s)):
                counter[s[j]] += 1
                bit = 1 << (ord(s[j]) - ord('a'))
                if counter[s[j]] < k:
                    mask |= bit
                else:
                    mask &= ~bit
                if mask == 0:
                    maxlen = max(maxlen, j - i + 1)
                    idx = j
            i = idx + 1
        return maxlen
