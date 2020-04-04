class Solution(object):
    def minRemoveToMakeValid(self, s):
        """
        :type s: str
        :rtype: str
        """
        invalid_index = set()
        stack = []
        for i, c in enumerate(s):
            if c == "(":
                stack.append(i)
            elif c == ")":
                if not stack:
                    invalid_index.add(i)
                else:
                    stack.pop()
        invalid_index |= set(stack)
        res = []
        for i, c in enumerate(s):
            if i not in invalid_index:
                res.append(c)
        return ''.join(res)

# Runtime: 164 ms, faster than 84.76% of Python online submissions for Minimum Remove to Make Valid Parentheses.
# Memory Usage: 15.1 MB, less than 100.00% of Python online submissions for Minimum Remove to Make Valid Parentheses.
