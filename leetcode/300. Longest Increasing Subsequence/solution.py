class Solution(object):
    def lengthOfLIS(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        # define dp[i] stores minimal num of any increasing
        # subsequence of length i+1, for cuurent num[i+1], we
        # need to find out the max length end with n, if not
        # found, then there is a new length, if found, we
        # need to update its minimal value
        dp = []
        for n in nums:
            l, r = 0, len(dp) - 1
            while l <= r:
                m = (l + r) / 2
                if dp[m] < n:
                    l = m + 1
                else:
                    r = m - 1
            if l >= len(dp):
                dp.append(n)
            else:
                dp[l] = n
        return len(dp)
