class Solution(object):
    def poorPigs(self, buckets, minutesToDie, minutesToTest):
        """
        :type buckets: int
        :type minutesToDie: int
        :type minutesToTest: int
        :rtype: int
        """
        # @o_sharp
        return int(math.log(buckets-1, minutesToTest//minutesToDie+1))+1 if buckets>1 else 0
