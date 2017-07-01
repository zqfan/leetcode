class Solution(object):
    def maximumProduct(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        mini, maxi = [-1001, -1001], [-1001, -1001, -1001]
        heapq.heapify(mini)
        heapq.heapify(maxi)
        for n in nums:
            heapq.heappushpop(mini, -n)
            heapq.heappushpop(maxi, n)
        return max(maxi[0] * maxi[1]* maxi[2], max(maxi) * mini[0] * mini[1])

# 83 / 83 test cases passed.
# Status: Accepted
# Runtime: 265 ms
