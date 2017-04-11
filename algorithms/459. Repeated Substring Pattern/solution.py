class Solution(object):
    def repeatedSubstringPattern(self, s):
        """
        :type s: str
        :rtype: bool
        """
        # refer: https://discuss.leetcode.com/topic/68206/easy-python-solution-with-explaination
        return (s +s ).find(s, 1, 2*len(s) - 1) != -1

# 107 / 107 test cases passed.
# Status: Accepted
# Runtime: 59 ms
# beats 74.48%
