class Solution(object):
    def findAnagrams(self, s, p):
        """
        :type s: str
        :type p: str
        :rtype: List[int]
        """
        if not s or len(s) < len(p):
            return []

        indices = []
        primes = [2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,
                  53,59,61,67,71,73,79,83,89,97,101]

        product_p = 1
        for c in p:
            product_p *= primes[ord(c) - ord('a')]

        product_s = 1
        for i in range(len(p)-1):
            product_s *= primes[ord(s[i]) - ord('a')]

        for j in range(len(p)-1, len(s)):
            product_s *= primes[ord(s[j]) - ord('a')]
            if product_s == product_p:
                indices.append(j-len(p)+1)
            product_s /= primes[ord(s[j-len(p)+1]) - ord('a')]

        return indices

# test
s = Solution().findAnagrams
assert s("cbaebabacd", "abc") == [0, 6]
