class Solution(object):
    def findAnagrams(self, s, p):
        """
        :type s: str
        :type p: str
        :rtype: List[int]
        """
        counter = [0] * 26
        for c in p:
            counter[ord(c) - ord('a')] += 1
        window = [0] * 26
        n, m = len(s), len(p)
        result = []
        for i in xrange(n):
            window[ord(s[i]) - ord('a')] += 1
            if i >= m:
                window[ord(s[i - m]) - ord('a')] -= 1
            if counter == window:
                result.append(i - m + 1)
        return result

# 36 / 36 test cases passed.
# Status: Accepted
# Runtime: 155 ms
