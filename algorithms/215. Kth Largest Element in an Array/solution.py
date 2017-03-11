class Solution(object):
    def findKthLargest(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        return Solution.find_kth_num(nums, k, 0, len(nums))

    @staticmethod
    def find_kth_num(nums, k, start, stop):
        if stop - start < 2:
            return nums[start]
        r = nums[random.randrange(start, stop)]
        e = u = start
        g = stop
        while u < g:
            if nums[u] > r:
                nums[u], nums[e] = nums[e], nums[u]
                e += 1
                u += 1
            elif nums[u] < r:
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
