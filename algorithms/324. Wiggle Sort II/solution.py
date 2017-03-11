class Solution(object):
    def wiggleSort(self, nums):
        """
        :type nums: List[int]
        :rtype: void Do not return anything, modify nums in-place instead.
        """
        if not nums:
            return
        median = Solution.find_kth_num(nums, (len(nums)+1)/2, 0, len(nums))
        # wiggle index
        def wi(i):
            return (2 * i + 1) % (len(nums) | 1)
        e = u = 0
        g = len(nums)
        while u < g:
            if nums[wi(u)] > median:
                nums[wi(u)], nums[wi(e)] = nums[wi(e)], nums[wi(u)]
                u += 1
                e += 1
            elif nums[wi(u)] < median:
                g -= 1
                nums[wi(u)], nums[wi(g)] = nums[wi(g)], nums[wi(u)]
            else:
                u += 1

    @staticmethod
    def find_kth_num(nums, k, start, stop):
        if stop - start < 2:
            return nums[start]
        r = nums[random.randrange(start, stop)]
        e = u = start
        g = stop
        while u < g:
            if nums[u] < r:
                nums[u], nums[e] = nums[e], nums[u]
                e += 1
                u += 1
            elif nums[u] > r:
                g -= 1
                nums[u], nums[g] = nums[g], nums[u]
            else:
                u += 1
        if k <= (e-start):
            return Solution.find_kth_num(nums, k, start, e)
        elif k > (g-start):
            return Solution.find_kth_num(nums, k-(g-start), g, stop)
        else:
            return nums[e]
