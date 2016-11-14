class Solution(object):
    def searchMatrix(self, matrix, target):
        """
        :type matrix: List[List[int]]
        :type target: int
        :rtype: bool
        """
        r, c = len(matrix), len(matrix[0])
        def search(si, sj, ei, ej):
            if not (0 <= si <= ei < r and 0 <= sj <= ej < c):
                return False
            mi = (si + ei) / 2
            mj = (sj + ej) / 2
            if matrix[mi][mj] > target:
                if search(si, sj, ei, mj-1):
                    return True
                return search(si, mj, mi-1, ej)
            elif matrix[mi][mj] < target:
                if search(mi+1, sj, ei, ej):
                    return True
                return search(si, mj+1, mi, ej)
            else:
                return True
        return search(0, 0, r-1, c-1)
