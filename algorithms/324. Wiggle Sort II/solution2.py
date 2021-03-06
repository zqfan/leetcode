class Solution(object):
    def wiggleSort(self, nums):
        """
        :type nums: List[int]
        :rtype: void Do not return anything, modify nums in-place instead.
        """
        tmp = nums[:]
        self.qsort(tmp, 0, len(nums))
        for i in range(1, len(nums), 2) + range(0, len(nums), 2):
            nums[i] = tmp.pop()

    @staticmethod
    def qsort(arr, start, stop):
        if stop - start < 2:
            return
        key = arr[random.randrange(start, stop)]
        e = u = 0
        g = stop
        while u < g:
            if arr[u] < key:
                arr[u], arr[e] = arr[e], arr[u]
                e += 1
                u += 1
            elif arr[u] > key:
                g -= 1
                arr[u], arr[g] = arr[g], arr[u]
            else:
                u += 1
        Solution.qsort(arr, start, e)
        Solution.qsort(arr, g, stop)
