class Solution(object):
    def removeDuplicateLetters(self, s):
        """
        :type s: str
        :rtype: str
        """
        # @lixx2100
        counter = collections.defaultdict(int)
        for c in s:
            counter[c] += 1
        visited = set()
        candidates = []
        for c in s:
            counter[c] -= 1
            if c in visited:
                continue
            while candidates and candidates[-1] > c and counter[candidates[-1]] > 0:
                visited.remove(candidates[-1])
                candidates.pop()
            visited.add(c)
            candidates.append(c)
        return ''.join(candidates)

# 286 / 286 test cases passed.
# Status: Accepted
# Runtime: 45 ms
# 94.37%
