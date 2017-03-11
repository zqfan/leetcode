class Solution(object):
    def majorityElement(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        if len(nums) < 2:
            return nums
        c1 = c2 = 0; n1 = n2 = nums[0]
        for n in nums:
            if n == n1:
                c1 += 1
            elif n == n2:
                c2 += 1
            elif c1 == 0:
                n1 = n
                c1 = 1
            elif c2 == 0:
                n2 = n
                c2 = 1
            else:
                c1 -= 1
                c2 -= 1
        c1 = c2 = 0
        for n in nums:
            if n == n1:
                c1 += 1
            elif n == n2:
                c2 += 1
        res = []
        if c1 > len(nums) / 3:
            res.append(n1)
        if c2 > len(nums) / 3:
            res.append(n2)
        return res
