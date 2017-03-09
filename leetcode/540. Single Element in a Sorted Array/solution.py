class Solution(object):
    def singleNonDuplicate(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        # if single element is in left side, then the middle duplicate ones
        # index will be (odd, even), otherwise, it will be (even, odd)
        l, r = 0, len(nums) - 1
        while l <= r:
            m = (l + r) / 2
            if m - 1 >= l and nums[m] == nums[m-1]:
                if m & 1:
                    l = m + 1
                else:
                    r = m - 2
            elif m + 1 <= r and nums[m] == nums[m+1]:
                if m & 1:
                    r = m - 1
                else:
                    l = m + 2
            else:
                return nums[m]
        # deal with invalid input: []
        return 0
