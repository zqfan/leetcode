class Solution(object):
    def getHint(self, secret, guess):
        """
        :type secret: str
        :type guess: str
        :rtype: str
        """
        A, B = 0, 0
        s_chr_count, g_chr_count = {}, {}
        for i in range(len(secret)):
            s, g = secret[i], guess[i]
            if s == g:
                A += 1
            s_chr_count[s] = s_chr_count.get(s, 0) + 1
            g_chr_count[g] = g_chr_count.get(g, 0) + 1
        for s in s_chr_count:
            B += min(s_chr_count[s], g_chr_count.get(s, 0))
        B -= A
        return "%sA%sB" % (A, B)

# test
s = Solution().getHint
assert s("1807", "7810") == "1A3B"
assert s("1123", "0111") == "1A1B"
