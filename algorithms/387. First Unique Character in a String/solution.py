class Solution(object):
    def firstUniqChar(self, s):
        """
        :type s: str
        :rtype: int
        """
        # chr_map = {chr: [last_index, count]}
        chr_map = {}
        for i, c in enumerate(s):
            if c not in chr_map:
                chr_map[c] = [i, 1]
            else:
                chr_map[c][0] = i
                chr_map[c][1] += 1
        min_index = -1
        for c in chr_map:
            if chr_map[c][1] > 1:
                continue
            if min_index == -1:
                min_index = chr_map[c][0]
            min_index = min(chr_map[c][0], min_index)
        return min_index

# test
s = Solution().firstUniqChar
assert 0 == s("leetcode")
assert 2 == s("loveleetcode")
assert -1 == s("")
assert -1 == s("aabbccdd")
