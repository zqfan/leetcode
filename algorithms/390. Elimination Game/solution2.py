class Solution(object):
    def lastRemaining(self, n):
        """
        :type n: int
        :rtype: int
        """
        # @NathanNi
        # we only consider the head, if head is removed, we update it
        head = step = left = 1
        while n > 1:
            if left or n & 1:
                head += step
            step *= 2
            n /= 2
            left ^= 1
        return head
