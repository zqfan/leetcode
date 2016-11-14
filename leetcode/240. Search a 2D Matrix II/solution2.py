class Solution(object):
    def searchMatrix(self, matrix, target):
        """
        :type matrix: List[List[int]]
        :type target: int
        :rtype: bool
        """
        for row in matrix:
            if row[0] <= target <= row[-1]:
                l, r = 0, len(row) - 1
                while l <= r:
                    m = (l + r) / 2
                    if row[m] < target:
                        l = m + 1
                    elif row[m] > target:
                        r = m - 1
                    else:
                        return True
        return False
