class Solution(object):
    def kthSmallest(self, matrix, k):
        """
        :type matrix: List[List[int]]
        :type k: int
        :rtype: int
        """
        n = len(matrix)
        h = [(matrix[i][0], i, 0) for i in xrange(n)]
        heapq.heapify(h)
        while k > 1:
            _, i, j = heapq.heappop(h)
            if j + 1 < n:
                heapq.heappush(h, (matrix[i][j+1], i, j+1))
            k -= 1
        return h[0][0]

# 85 / 85 test cases passed.
# Status: Accepted
# Runtime: 308 ms
# beats 19.74 %
