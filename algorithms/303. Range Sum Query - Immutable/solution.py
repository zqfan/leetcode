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

    def sumRange(self, i, j):
        """
        sum of elements nums[i..j], inclusive.
        :type i: int
        :type j: int
        :rtype: int
        """
        assert 0 <= i <= j <= len(self.nums)
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
# numArray.sumRange(1, 2)

# test
s = NumArray([-2, 0, 3, -5, 2, -1]).sumRange
assert s(0, 2) == 1
assert s(2, 5) == -1
assert s(0, 5) == -3
