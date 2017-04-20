class Solution(object):
    def reconstructQueue(self, people):
        """
        :type people: List[List[int]]
        :rtype: List[List[int]]
        """
        heap = [(k, h) for h, k in people]
        heapq.heapify(heap)
        result = []
        while heap:
            k, h = heapq.heappop(heap)
            ge = 0
            for i in xrange(len(result)):
                if h <= result[i][0]:
                    ge += 1
                if ge > k:
                    result.insert(i, [h, k])
                    break
            else:
                result.append([h, k])
        return result

# 37 / 37 test cases passed.
# Status: Accepted
# Runtime: 709 ms
# beats 15.11%
