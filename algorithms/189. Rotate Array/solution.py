class Solution(object):
    def rotate(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: void Do not return anything, modify nums in-place instead.
        """
        if not nums:
            return

        def swap(p1, p2):
            for i in range(k):
                nums[p1+i], nums[p2+i] = nums[p2+i], nums[p1+i]

        l = len(nums)
        p1 = 0
        k = k % l
        while p1 < l and k != 0:
            k = k % (l - p1)
            swap(p1, l - k)
            p1 += k
