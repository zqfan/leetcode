class Solution(object):
    def splitArray(self, nums, m):
        """
        :type nums: List[int]
        :type m: int
        :rtype: int
        """
        # @dax1ng
        def can_split(upmost):
            slices = 1; total = 0
            for n in nums:
                total += n
                if total > upmost:
                    total = n
                    slices += 1
                    if slices > m:
                        return False
            return True

        l = max(nums); r = sum(nums)
        while l <= r:
            mid = (l + r) / 2
            if can_split(mid):
                r = mid - 1
            else:
                l = mid + 1
        return l

# 28 / 28 test cases passed.
# Status: Accepted
# Runtime: 65 ms
# 92.74%
