class Solution(object):
    def findDiagonalOrder(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: List[int]
        """
        res = []
        m = len(matrix)
        n = len(matrix and matrix[0])
        reverted = False
        for i in xrange(m):
            j = 0
            num_arr = []
            while i >= 0 and j < n:
                num_arr.append(matrix[i][j])
                i -= 1
                j += 1
            if reverted:
                res.extend(num_arr[::-1])
            else:
                res.extend(num_arr)
            reverted = not reverted
        for j in xrange(1, n):
            i = m - 1
            num_arr = []
            while i >= 0 and j < n:
                num_arr.append(matrix[i][j])
                i -= 1
                j += 1
            if reverted:
                res.extend(num_arr[::-1])
            else:
                res.extend(num_arr)
            reverted = not reverted
        return res
