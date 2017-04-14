class NumArray(object):

    def __init__(self, nums):
        """
        :type nums: List[int]
        """
        self.sums = [0]
        for n in nums:
            self.sums.append(self.sums[-1] + n)

    def sumRange(self, i, j):
        """
        :type i: int
        :type j: int
        :rtype: int
        """
        return self.sums[j + 1] - self.sums[i]


# Your NumArray object will be instantiated and called as such:
# obj = NumArray(nums)
# param_1 = obj.sumRange(i,j)
