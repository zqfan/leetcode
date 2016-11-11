class Solution(object):
    def kthSmallest(self, matrix, k):
        """
        :type matrix: List[List[int]]
        :type k: int
        :rtype: int
        """
        heap = [(matrix[0][0], 0, 0)]
        heapq.heapify(heap)
        flag = [[0]*len(matrix[0]) for i in range(len(matrix))]
        n = 0
        while k:
            n, i, j = heapq.heappop(heap)
            if i < len(matrix)-1 and not flag[i+1][j]:
                heapq.heappush(heap, (matrix[i+1][j], i+1, j))
                flag[i+1][j] = 1
            if j < len(matrix[0])-1 and not flag[i][j+1]:
                heapq.heappush(heap, (matrix[i][j+1], i, j+1))
                flag[i][j+1] = 1
            k -= 1
        return n
