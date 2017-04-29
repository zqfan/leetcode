class Solution(object):
    def decodeString(self, s):
        """
        :type s: str
        :rtype: str
        """
        # @ayushpatwari
        stack = [["", 1]]
        n = 0
        for c in s:
            if c.isdigit():
                n = n * 10 + int(c)
            elif c.isalpha():
                stack[-1][0] += c
            elif c == '[':
                stack.append(["", n])
                n = 0
            elif c == ']':
                subs, count = stack.pop()
                stack[-1][0] += subs * count
        return stack[0][0]
