class Solution(object):
    def smallestRange(self, nums):
        """
        :type nums: List[List[int]]
        :rtype: List[int]
        """
        h = [[a[0], i, 0] for i, a in enumerate(nums)]
        heapq.heapify(h)
        result = [float('-inf'), float('inf')]
        right = max(a[0] for a in nums)
        while True:
            left, i, j = heapq.heappop(h)
            if right - left < result[1] - result[0]:
                result = [left, right]
            if j + 1 == len(nums[i]):
                return result
            right = max(right, nums[i][j+1])
            heapq.heappush(h, [nums[i][j+1], i, j+1])
