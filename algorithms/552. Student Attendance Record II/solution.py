import numpy

class Solution(object):
    def checkRecord(self, n):
        """
        :type n: int
        :rtype: int
        """
        # @StefanPochmann
        m = 10 ** 9 + 7
        A = numpy.matrix([[0, 0, 1, 0, 0, 0],
                          [1, 0, 1, 0, 0, 0],
                          [0, 1, 1, 0, 0, 0],
                          [0, 0, 1, 0, 0, 1],
                          [0, 0, 1, 1, 0, 1],
                          [0, 0, 1, 0, 1, 1]])
        record = A
        while n > 0:
            if n & 1:
                record = (record * A) % m
            A = (A * A) % m
            n /= 2
        return int(record[5, 2])

# 58 / 58 test cases passed.
# Status: Accepted
# Runtime: 128 ms
