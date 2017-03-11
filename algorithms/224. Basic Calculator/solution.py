class Solution(object):
    def calculate(self, s):
        """
        :type s: str
        :rtype: int
        """
        stack = []
        n = 0
        has_digit = 0
        for c in s:
            if c.isdigit():
                n *= has_digit
                has_digit = 1
                n = n * 10 + int(c)
            elif c in ('+', '-', ')'):
                if has_digit:
                    if stack and stack[-1] != '(':
                        op = stack.pop()
                        n1 = stack.pop()
                        n = op(n1, n)
                    stack.append(n)
                    has_digit = 0
                if c == '+':
                    stack.append(operator.add)
                elif c == '-':
                    stack.append(operator.sub)
                else:
                    n = stack.pop()
                    stack.pop()
                    if stack and stack[-1] != '(':
                        op = stack.pop()
                        n1 = stack.pop()
                        n = op(n1, n)
                    stack.append(n)
            elif c == '(':
                stack.append('(')
        if has_digit:
            stack.append(n)
        if len(stack) > 2:
            return stack[1](stack[0], stack[2])
        return stack[0]
