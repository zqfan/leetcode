class Solution(object):
    def search(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        def find(start, end):
            if start > end:
                return -1
            mid = (start + end) / 2
            # left is sorted
            if nums[start] <= nums[mid]:
                if nums[start] <= target and target <= nums[mid]:
                    p = bisect.bisect_left(nums, target, start, mid+1)
                    return p if p <= mid and nums[p] == target else -1
                else:
                    return find(mid + 1, end)
            # right is sorted
            else:
                if nums[mid+1] <= target and target <= nums[end]:
                    p = bisect.bisect_left(nums, target, mid+1, end+1)
                    return p if p <= end and nums[p] == target else -1
                else:
                    return find(start, mid)
        return find(0, len(nums) - 1)
