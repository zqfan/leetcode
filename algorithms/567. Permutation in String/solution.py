class Solution(object):
    def checkInclusion(self, s1, s2):
        """
        :type s1: str
        :type s2: str
        :rtype: bool
        """
        n1, n2 = len(s1), len(s2)
        if n1 > n2:
            return False
        counter = [0] * 26
        for c in s1:
            counter[ord(c) - 97] += 1
        window = [0] * 26
        for i, c in enumerate(s2):
            window[ord(c) - 97] += 1
            if i >= n1:
                window[ord(s2[i - n1]) - 97] -= 1
            if counter == window:
                return True
        return False

# 101 / 101 test cases passed.
# Status: Accepted
# Runtime: 82 ms
