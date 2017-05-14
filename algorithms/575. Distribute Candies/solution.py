class Solution(object):
    def distributeCandies(self, candies):
        """
        :type candies: List[int]
        :rtype: int
        """
        # @awice
        return min(len(candies) / 2, len(set(candies)))
