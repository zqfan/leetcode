class NumArray(object):
    def __init__(self, nums):
        """
        initialize your data structure here.
        :type nums: List[int]
        """
        self.nums = nums
        self.sum_slices = []
        self.slice_width = 100
        i = 0
        while (i + self.slice_width) < len(self.nums):
            self.sum_slices.append(sum(nums[i:i + self.slice_width]))
            i += self.slice_width

    def update(self, i, val):
        """
        :type i: int
        :type val: int
        :rtype: int
        """
        idx = i / self.slice_width
        if idx < len(self.sum_slices):
            self.sum_slices[idx] -= self.nums[i] - val
        self.nums[i] = val

    def sumRange(self, i, j):
        """
        sum of elements nums[i..j], inclusive.
        :type i: int
        :type j: int
        :rtype: int
        """
        start, end = (i / self.slice_width) + 1, j / self.slice_width
        total = 0
        if start < end:
            total += sum(self.sum_slices[start:end])
            total += sum(self.nums[i:start * self.slice_width])
            total += sum(self.nums[end * self.slice_width:j + 1])
        else:
            total += sum(self.nums[i:j + 1])
        return total

# Your NumArray object will be instantiated and called as such:
# numArray = NumArray(nums)
# numArray.sumRange(0, 1)
# numArray.update(1, 10)
# numArray.sumRange(1, 2)

# 10 / 10 test cases passed.
# Status: Accepted
# Runtime: 129 ms
# 99.44%
