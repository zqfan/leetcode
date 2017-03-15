class Solution(object):
    def lastRemaining(self, n):
        """
        :type n: int
        :rtype: int
        """
        # @zhangyiwei
        # After first elimination, all the rest numbers are even numbers.
        # Divide by 2, we get a continuous new sequence from 1 to n / 2.
        # For this sequence we start from right to left as the first elimination.
        # Then the original result should be two times the mirroring result of lastRemaining(n / 2).
        return 2 * (1 + n / 2 - self.lastRemaining(n / 2)) if n > 1 else 1
