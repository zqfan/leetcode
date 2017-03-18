class Solution(object):
    def countDigitOne(self, n):
        """
        :type n: int
        :rtype: int
        """
        # we count 1 for every position, from lowest to highest
        cnt = 0
        s = 1
        m = n
        while m > 0:
            # all numbers are met, for example 65535, we have
            # 0-6553 number of 1 in lowest position
            if m % 10 > 1:
                cnt += (m / 10 + 1) * s
            # all and part of last one are met
            elif m % 10 == 1:
                cnt += (m / 10) * s + (n % s + 1)
            # all but one are met
            else:
                cnt += (m / 10) * s
            m /= 10
            s *= 10
        return cnt
