class Solution(object):
    def isPossible(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        h = []
        for n in nums:
            while h and n > h[0][0] + 1:
                if heapq.heappop(h)[1] < 3:
                    return False
            if not h or n == h[0][0]:
                heapq.heappush(h, [n, 1])
            elif n == h[0][0] + 1:
                m, l = heapq.heappop(h)
                heapq.heappush(h, [n, l + 1])
        return all(l > 2 for n, l in h)

# 180 / 180 test cases passed.
# Status: Accepted
# Runtime: 152 ms
# beats 89.41 %
