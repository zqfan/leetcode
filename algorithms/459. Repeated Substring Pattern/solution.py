class Solution(object):
    def repeatedSubstringPattern(self, str):
        """
        :type str: str
        :rtype: bool
        """
        # refer: https://discuss.leetcode.com/topic/68206/easy-python-solution-with-explaination
        return (str+str).find(str, 1, 2*len(str)-1) != -1
