class Solution(object):
    def maxSlidingWindow(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: List[int]
        """
        res = []
        deque = collections.deque()
        for i, n in enumerate(nums):
            while deque and deque[-1] < (n, i):
                deque.pop()
            deque.append((n, i))
            idx = i+1-k
            if idx >= 0:
                res.append(deque[0][0])
                if (nums[idx], idx) == deque[0]:
                    deque.popleft()
        return res

# 18 / 18 test cases passed.
# Status: Accepted
# Runtime: 189 ms
# 81.41%
