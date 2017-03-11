class Solution(object):
    def lexicalOrder(self, n):
        """
        :type n: int
        :rtype: List[int]
        """
        ret = []
        stack = [1]
        while len(ret) < n:
            t = stack.pop()
            ret.append(t)
            if t < n and t % 10 < 9:
                stack.append(t+1)
            if t * 10 <= n:
                stack.append(t * 10)
        return ret
