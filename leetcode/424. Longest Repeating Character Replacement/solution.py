class Solution(object):
    def characterReplacement(self, s, k):
        """
        :type s: str
        :type k: int
        :rtype: int
        """
        # sliding window
        counter = collections.defaultdict(int)
        max_len = max_count = p1 = p2 = 0
        while p2 < len(s):
            counter[s[p2]] += 1
            max_count = max(max_count, counter[s[p2]])
            p2 += 1
            while p2 - p1 - max_count > k:
                counter[s[p1]] -= 1
                max_count = max(counter.itervalues())
                p1 += 1
            max_len = max(max_len, p2 - p1)
        return max_len
