class Solution(object):
    def searchMatrix(self, matrix, target):
        """
        :type matrix: List[List[int]]
        :type target: int
        :rtype: bool
        """
        m, n = len(matrix), len(matrix[0]) if matrix else 0
        l, r = 0, m * n - 1
        while l <= r:
            mid = (l + r) / 2
            num = matrix[mid / n][mid % n]
            if target < num:
                r = mid - 1
            elif target > num:
                l = mid + 1
            else:
                return True
        return False
