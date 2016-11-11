class Solution(object):
    def kthSmallest(self, matrix, k):
        """
        :type matrix: List[List[int]]
        :type k: int
        :rtype: int
        """
        l = matrix[0][0]
        r = matrix[-1][-1]
        while l < r:
            m = (l + r) / 2
            c = 0
            i = len(matrix) - 1
            j = 0
            while i >= 0 and j < len(matrix[0]):
                if matrix[i][j] <= m:
                    c += i + 1
                    j += 1
                else:
                    i -= 1
            if c < k:
                l = m + 1
            else:
                r = m
        return l
