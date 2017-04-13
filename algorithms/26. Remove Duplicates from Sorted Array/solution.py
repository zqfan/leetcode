class Solution(object):
    def removeDuplicates(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if not nums:
            return 0
        i = 0
        for n in nums:
            if n != nums[i]:
                i += 1
                nums[i] = n
        return i + 1
