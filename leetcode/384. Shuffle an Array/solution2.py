import random

class Solution(object):

    def __init__(self, nums):
        """
        :type nums: List[int]
        :type size: int
        """
        self.nums = nums

    def reset(self):
        """
        Resets the array to its original configuration and return it.
        :rtype: List[int]
        """
        return self.nums

    def shuffle(self):
        """
        Returns a random shuffling of the array.
        :rtype: List[int]
        """
        l = len(self.nums)
        shuffled_nums = self.nums[:]
        for i in range(l):
            p = random.randint(0, l-1)
            shuffled_nums[p], shuffled_nums[l-1-i] = shuffled_nums[l-1-i], shuffled_nums[p]
        return shuffled_nums


# Your Solution object will be instantiated and called as such:
# obj = Solution(nums)
# param_1 = obj.reset()
# param_2 = obj.shuffle()
