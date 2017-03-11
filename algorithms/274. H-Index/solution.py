class Solution(object):
    def hIndex(self, citations):
        """
        :type citations: List[int]
        :rtype: int
        """
        counter = [0] * (len(citations) + 1)
        for c in citations:
            if c > len(citations):
                counter[-1] += 1
            else:
                counter[c] += 1
        for i in xrange(len(citations), 0, -1):
            if counter[i] >= i:
                return i
            counter[i-1] += counter[i]
        return 0
