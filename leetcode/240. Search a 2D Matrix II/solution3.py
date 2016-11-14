class Solution(object):
    def searchMatrix(self, matrix, target):
        """
        :type matrix: List[List[int]]
        :type target: int
        :rtype: bool
        """
        r, c = len(matrix), len(matrix[0])
        queue = collections.deque()
        queue.append((0, 0, r-1, c-1))
        while queue:
            si, sj, ei, ej = queue.popleft()
            if not (0 <= si <= ei < r and 0 <= sj <= ej < c):
                continue
            mi = (si + ei) / 2
            mj = (sj + ej) / 2
            if matrix[mi][mj] > target:
                queue.append((si, sj, ei, mj-1))
                if matrix[si][mj] <= target:
                    queue.append((si, mj, mi-1, ej))
            elif matrix[mi][mj] < target:
                queue.append((mi+1, sj, ei, ej))
                if matrix[mi][ej] >= target:
                    queue.append((si, mj+1, mi, ej))
            else:
                return True
        return False
