class Solution(object):
    def bulbSwitch(self, n):
        """
        :type n: int
        :rtype: int
        """
        on_bulbs = 0
        i = 1
        while i * i <= n:
            on_bulbs += 1
            i += 1
        return on_bulbs
