class Solution(object):
    def find132pattern(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        s3 = -sys.maxsize
        stack = []
        for s1 in reversed(nums):
            if s1 < s3:
                return True
            while stack and s1 > stack[-1]:
                s3 = stack.pop()
            stack.append(s1)
        return False
