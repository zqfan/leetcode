class Solution:
    def reverseParentheses(self, s: str) -> str:
        stack = [[]]
        for c in s:
            if c == "(":
                stack.append([])
            elif c == ")":
                top = stack.pop()
                stack[-1] += top[::-1]
            else:
                stack[-1].append(c)
        return ''.join(stack[-1])
