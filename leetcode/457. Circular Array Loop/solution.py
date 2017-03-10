class Solution(object):
    def circularArrayLoop(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        def nextidx(idx):
            return (idx + nums[idx] + len(nums)) % len(nums)

        for i in xrange(len(nums)):
            if nums[i] == 0:
                continue
            slow, fast = i, nextidx(i)
            while nums[slow] * nums[fast] > 0 and nums[slow] * nums[nextidx(fast)] > 0:
                if slow == fast:
                    if slow != nextidx(slow):
                        return True
                    break
                slow = nextidx(slow)
                fast = nextidx(nextidx(fast))
            # not found, set visited path to 0 to make it o(n)
            slow, factor = i, nums[i]
            while factor * nums[slow] > 0:
                nums[slow], slow = 0, nextidx(slow)
        return False
