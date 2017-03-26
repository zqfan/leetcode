class Solution(object):
    def checkPerfectNumber(self, num):
        """
        :type num: int
        :rtype: bool
        """
        if num < 2:
            return False
        total = -num
        for i in xrange(1, num):
            if i * i > num:
                break
            if num % i == 0:
                total += i + num / i
                if num / i == i:
                    total -= i
        return total == num
