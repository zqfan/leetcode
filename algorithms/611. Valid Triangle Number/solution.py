class Solution(object):
    def triangleNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        nums, count, n = sorted(nums, reverse=1), 0, len(nums)
        for i in xrange(n):
            j, k = i + 1, n - 1
            while j < k:
                # any value x between j...k will satisfy nums[j] + nums[x] > nums[i]
                # and because nums[i] > nums[j] > nums[x] >= 0, they will always satisfy
                # nums[i] + nums[x] > nums[j] and nums[i] + nums[j] > nums[x]
                if nums[j] + nums[k] > nums[i]:
                    count += k - j
                    j += 1
                else:
                    k -= 1
        return count

# 243 / 243 test cases passed.
# Status: Accepted
# Runtime: 1855 ms
