class Solution(object):
    def maxSlidingWindow(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: List[int]
        """
        res = []
        window_heap = []
        remain_heap = []
        for i, n in enumerate(nums):
            heapq.heappush(window_heap, -n)
            idx = i+1-k
            if idx >= 0:
                res.append(-window_heap[0])
                if nums[idx] == res[-1]:
                    heapq.heappop(window_heap)
                    while remain_heap and window_heap[0] == remain_heap[0]:
                        heapq.heappop(window_heap)
                        heapq.heappop(remain_heap)
                else:
                    heapq.heappush(remain_heap, -nums[idx])
        return res

# 18 / 18 test cases passed.
# Status: Accepted
# Runtime: 339 ms
# 20.62%
