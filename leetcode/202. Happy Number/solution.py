class Solution(object):
    def isHappy(self, n):
        """
        :type n: int
        :rtype: bool
        """
        if n < 1:
            return False
        histories = set()
        while n != 1:
            n = sum([int(d) * int(d) for d in str(n)])
            if n in histories:
                return False
            histories.add(n)
        return True
