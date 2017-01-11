class Solution(object):
    def poorPigs(self, buckets, minutesToDie, minutesToTest):
        """
        :type buckets: int
        :type minutesToDie: int
        :type minutesToTest: int
        :rtype: int
        """
        # @StefanPochmann
        pigs = 0
        rounds = minutesToTest / minutesToDie + 1
        while rounds ** pigs < buckets:
            pigs += 1
        return pigs
