class Solution(object):
    def moveZeroes(self, nums):
        """
        :type nums: List[int]
        :rtype: void Do not return anything, modify nums in-place instead.
        """
        def _find_zero(start):
            while start < len(nums) and nums[start] != 0:
                start += 1
            return start

        def _find_non_zero(start):
            while start < len(nums) and nums[start] == 0:
                start += 1
            return start

        pos_0 = _find_zero(0)
        pos_n_0 = _find_non_zero(pos_0 + 1)
        while pos_0 < pos_n_0 < len(nums):
            nums[pos_0], nums[pos_n_0] = nums[pos_n_0], nums[pos_0]
            pos_0 = _find_zero(pos_0)
            pos_n_0 = _find_non_zero(pos_n_0)

# test
s = Solution().moveZeroes
l = [0, 1, 0, 3, 12]
s(l)
assert [1, 3, 12, 0, 0] == l
# fail test
l = [1, 0]
s(l)
assert [1, 0] == l
# fail test 2, I'm noob
l = [1, 0, 1]
s(l)
assert [1, 1, 0] == l
