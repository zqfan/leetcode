class Solution(object):
    def findLongestChain(self, pairs):
        """
        :type pairs: List[List[int]]
        :rtype: int
        """
        pairs = sorted(pairs)
        result = 1
        end = pairs[0][1]
        for i in xrange(1, len(pairs)):
            if pairs[i][0] <= end:
                end = min(end, pairs[i][1])
            else:
                result += 1
                end = pairs[i][1]
        return result
