class Solution(object):
    def maxProduct(self, words):
        """
        :type words: List[str]
        :rtype: int
        """
        fp_arr = []  # fingerprint of word
        for w in words:
            fp = sum([1<<(ord(c)-ord('a')) for c in set(w)])
            fp_arr.append(n)
        maxp = 0
        for i, fpi in enumerate(fp_arr):
            for j in range(i+1, len(words)):
                p = len(words[i]) * len(words[j])
                if (p > maxp) and not (fpi & fp_arr[j]):
                    maxp = p
        return maxp
