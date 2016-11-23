class Solution(object):
    def summaryRanges(self, nums):
        """
        :type nums: List[int]
        :rtype: List[str]
        """
        res = []; start = 0; l = len(nums)
        for end in xrange(l):
            if end+1 >= l or nums[end+1] - nums[end] > 1:
                if nums[end] != nums[start]:
                    res.append("%s->%s" % (nums[start], nums[end]))
                else:
                    res.append(str(nums[start]))
                start = end + 1
        return res
