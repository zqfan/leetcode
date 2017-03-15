class Solution(object):
    def maxSumSubmatrix(self, matrix, k):
        """
        :type matrix: List[List[int]]
        :type k: int
        :rtype: int
        """
        # code by @quanhoang and @TeXnician
        m, n = len(matrix), len(matrix[0])
        M, N = min(m,n), max(m,n)
        ans = None
        def findMaxArea(sums, beg, end):
        	if beg + 1 >= end: return None
        	mid = beg + ((end - beg)>>1)
        	res = max(findMaxArea(sums, beg, mid), findMaxArea(sums, mid, end))
        	i = mid
        	for l in sums[beg:mid]:
        		while i < len(sums) and sums[i] - l <= k:
        			res = max(res, sums[i] - l)
        			i += 1
        	sums[beg:end] = sorted(sums[beg:end])
        	return res

        for i1 in xrange(M):
        	tmp = [0]*N
        	for i2 in xrange(i1, M):
        		sums, low, maxArea = [0], 0, None
        		for j in xrange(N):
        			tmp[j] += matrix[i2][j] if m <= n else matrix[j][i2]
        			sums.append(sums[-1] + tmp[j])
        			maxArea = max(maxArea, sums[-1] - low)
        			low = min(low, sums[-1])
        		if maxArea <= ans: continue
        		if maxArea == k: return k
        		if maxArea > k: maxArea = findMaxArea(sums, 0, N+1)
        		ans = max(ans, maxArea)
        return ans or 0
