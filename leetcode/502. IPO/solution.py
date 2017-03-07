class Solution(object):
    def findMaximizedCapital(self, k, W, Profits, Capital):
        """
        :type k: int
        :type W: int
        :type Profits: List[int]
        :type Capital: List[int]
        :rtype: int
        """
        cap2pro = sorted(zip(Capital, Profits), reverse=1)
        maxpro = []
        for i in xrange(k):
            while cap2pro and cap2pro[-1][0] <= W:
                heapq.heappush(maxpro, -cap2pro.pop()[1])
            if maxpro:
                W += -heapq.heappop(maxpro)
        return W
