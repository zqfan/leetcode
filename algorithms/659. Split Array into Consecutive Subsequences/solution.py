class Solution(object):
    def isPossible(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        def possible(start, end):
            l1 = l2 = pre = 0
            cnt = 1
            for i in xrange(start + 1, end + 1):
                if i < end and nums[i] == nums[i-1]:
                    cnt += 1
                else:
                    if cnt < l1 + l2:
                        return False
                    l2 = l1
                    l1 = max(0, cnt - pre)
                    pre = cnt
                    cnt = 1
            return l1 == l2 == 0

        k = 0
        for i in xrange(1, len(nums)):
            if nums[i] - nums[i-1] > 1:
                if not possible(k, i):
                    return False
                i = k
        return possible(k, len(nums))

# 180 / 180 test cases passed.
# Status: Accepted
# Runtime: 105 ms
# beats 94.80 %
