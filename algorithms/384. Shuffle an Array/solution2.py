class Solution(object):

    def __init__(self, nums):
        """
        :type nums: List[int]
        """
        self.nums = nums

    def reset(self):
        """
        Resets the array to its original configuration and return it.
        :rtype: List[int]
        """
        return self.nums[:]

    def shuffle(self):
        """
        Returns a random shuffling of the array.
        :rtype: List[int]
        """
        s = self.nums[:]
        for i in xrange(len(s)):
            p = random.randrange(i, len(s))
            s[i], s[p] = s[p], s[i]
        return s


# Your Solution object will be instantiated and called as such:
# obj = Solution(nums)
# param_1 = obj.reset()
# param_2 = obj.shuffle()
