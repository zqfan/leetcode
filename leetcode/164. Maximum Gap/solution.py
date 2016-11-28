class Solution(object):
    def maximumGap(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        # @zkfairytale
        if len(nums) < 2:
            return 0
        maximal = max(nums)
        minimum = min(nums)
        gap = int(math.ceil(float(maximal-minimum)/(len(nums)-1)))
        minbuckets = [1<<31] * (len(nums) - 1)
        maxbuckets = [0] * (len(nums) - 1)
        for n in nums:
            if minimum == n or n == maximal:
                continue
            idx = (n - minimum) / gap
            minbuckets[idx] = min(minbuckets[idx], n)
            maxbuckets[idx] = max(maxbuckets[idx], n)
        maxgap = 0
        pre = minimum
        for i in xrange(len(nums) - 1):
            if maxbuckets[i] != 0:
                maxgap = max(maxgap, minbuckets[i] - pre)
                pre = maxbuckets[i]
        return max(maxgap, maximal - pre)

# 17 / 17 test cases passed.
# Status: Accepted
# Runtime: 52 ms
# 82.10%
