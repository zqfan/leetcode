class Solution(object):
    def rotate(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: void Do not return anything, modify nums in-place instead.
        """
        if (not nums) or (k % len(nums)) == 0:
            return

        def swap(start):
            for i in range(k):
                nums[start+i], nums[l-k+i] = nums[l-k+i], nums[start+i]

        l = len(nums)
        start = 0
        k = k % l
        while start < l and k != 0:
            k = k % (l - start)
            swap(start)
            start += k

    def rotate1(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: void Do not return anything, modify nums in-place instead.
        """
        l = len(nums)
        k = k % l
        nums[:] = nums[l-k:] + nums[:l-k]
