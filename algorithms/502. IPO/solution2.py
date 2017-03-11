class Solution(object):
    def findMaximizedCapital(self, k, W, Profits, Capital):
        """
        :type k: int
        :type W: int
        :type Profits: List[int]
        :type Capital: List[int]
        :rtype: int
        """
        cap2pro = zip(Capital, Profits)
        heapq.heapify(cap2pro)
        maxpro = []
        for i in xrange(k):
            while cap2pro and cap2pro[0][0] <= W:
                cap, pro = heapq.heappop(cap2pro)
                heapq.heappush(maxpro, -pro)
            if maxpro:
                W += -heapq.heappop(maxpro)
        return W
