class Solution(object):
    def findMaxAverage(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: float
        """
        # @ awice
        # to avoid TLE for python
        # If a segment has the biggest average and we break it into two pieces,
        # one of its pieces also has at least the same average.
        # When the length is >= 2*K,
        # we can split it into pieces of at least length K,
        # with the largest such piece being less than length 2*K.
        if k < 100:
            result = float('-inf')
            presum = [0]
            for n in nums:
                presum.append(presum[-1] + n)
            for w in xrange(k, min(2 * k, len(nums) + 1)):
                maxsum = max(presum[w + i] - presum[i] for i in xrange(len(nums) - w + 1))
                result = max(result, maxsum / float(w))
            return result

        def possible(m):
            s = ks = mins = 0
            for i in xrange(k):
                s += nums[i] - m
            if s >= 0:
                return True
            for i in xrange(k, len(nums)):
                s += nums[i] - m
                ks += nums[i-k] - m
                mins = min(mins, ks)
                if s >= mins:
                    return True
            return False

        lo, hi = min(nums), max(nums)
        while hi - lo >= 1e-5:
            mid = (lo + hi) / 2.0
            if possible(mid):
                lo = mid
            else:
                hi = mid
        return lo

# 74 / 74 test cases passed.
# Status: Accepted
# Runtime: 1659 ms
# beats 15.20 %
