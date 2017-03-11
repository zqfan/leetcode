class Solution(object):
    def singleNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        # this solution is too hard to understand, and can only
        # deal with this specific case, so it is not a good solution
        #
        # p12 means bits that appear one or two times
        # p2 means bits that appear only two times
        # p3 means bits that appear three times
        #
        # to get p3, we use last p2 and count current number
        #
        # to get p2, we use last p12 and count current number,
        # and plus last p2 without counting current number,
        # but beware that, current p2 may contain bits that appear
        # three times which is caused by p12, so we need to clear them
        #
        # to get p12, we always use last p12 and count current number,
        # beware that current p12 may contain bits that appear three
        # times, so we need to clear them
        p12 = p2 = p3 = 0
        for n in nums:
            p3 = p2 & n
            p2 = (p2 | p12 & n) & ~p3
            p12 = (p12 | n ) & ~p3
        return p12
