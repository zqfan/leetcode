class Solution(object):
    def maxProduct(self, words):
        """
        :type words: List[str]
        :rtype: int
        """
        # refer: http://bookshadow.com/weblog/2015/12/16/leetcode-maximum-product-word-lengths/
        # if c not in a word, store word's fingerprint to [c]
        nc_arr = [set() for i in range(26)]
        # fingerprint's max length, size could be len(words)
        fp_mlen = collections.defaultdict(int)
        for w in words:
            chr_set = set(w)
            fp = sum([1<<(ord(c)-ord('a')) for c in chr_set])
            fp_mlen[fp] = max(fp_mlen[fp], len(w))
            for c in string.lowercase:
                if c not in chr_set:
                    nc_arr[ord(c)-ord('a')].add(fp)
        max_len = 0
        for w in words:
            chr_set = set(w)
            s = [nc_arr[ord(c)-ord('a')] for c in chr_set]
            if not s:
                continue
            for n in set.intersection(*s):
                max_len = max(max_len, len(w)*fp_mlen[n])
        return max_len
