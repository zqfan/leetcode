class Solution(object):
    def findMaxAverage(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: float
        """
        # inspired by @ awice
        def avg(i, j):
            return (presum[j+1] - presum[i]) / float(j + 1 - i)

        presum = [0]
        for n in nums:
            presum.append(presum[-1] + n)
        # convex hull processing
        hull = collections.deque()
        result = float('-inf')
        for i in xrange(k - 1, len(nums)):
            while len(hull) > 1 and avg(hull[-2], hull[-1] - 1) >= avg(hull[-2], i - k):
                hull.pop()
            hull.append(i - k + 1)
            while len(hull) > 1 and avg(hull[0], hull[1] - 1) <= avg(hull[0], i):
                hull.popleft()
            result = max(result, avg(hull[0], i))
        return result

# 74 / 74 test cases passed.
# Status: Accepted
# Runtime: 696 ms
