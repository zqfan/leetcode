class Solution(object):
    def removeKdigits(self, num, k):
        """
        :type num: str
        :type k: int
        :rtype: str
        """
        if len(num) <= k:
            return '0'
        l = list(num)
        while k > 0:
            for i in xrange(len(l)-1):
                if l[i] > l[i+1]:
                    del l[i]
                    break
            else:
                l.pop()
            k -= 1
        res = ''.join(l).lstrip('0')
        return res or '0'
