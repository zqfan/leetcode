class Solution(object):
    def reversePairs(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        def merge_sort(start, end):
            middle = (start + end) / 2
            if middle == start:
                return
            merge_sort(start, middle)
            merge_sort(middle, end)
            l, r = middle - 1, end - 1
            while l >= start and r >= middle:
                if nums[l] <= nums[r] * 2:
                    r -= 1
                else:
                    rp[0] += r - middle + 1
                    l -= 1
            nums[start:end] = sorted(nums[start:end])

        rp = [0]
        merge_sort(0, len(nums))
        return rp[0]
