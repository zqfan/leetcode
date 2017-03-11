class Solution(object):
    def find132pattern(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        s2 = s3 = None
        stack = []
        for s1 in reversed(nums):
            if s3 is not None and s1 < s3:
                return True
            elif s2 is not None and s1 <= s2:
                if not stack or s3 < s1 < stack[-1]:
                    stack.append(s1)
                while stack and s1 > stack[-1]:
                    s3 = stack.pop()
                    s2 = s1
            elif s1 > s2:
                s3 = s2
                s2 = s1
        return False
