class Solution(object):
    def removeKdigits(self, num, k):
        """
        :type num: str
        :type k: int
        :rtype: str
        """
        stack = []
        i = 0
        while k and i < len(num):
            while k and stack and stack[-1] > num[i]:
                stack.pop()
                k -= 1
            stack.append(num[i])
            i += 1
        while k:
            stack.pop()
            k -= 1
        res = (''.join(stack)+num[i:]).lstrip('0')
        return res or '0'
