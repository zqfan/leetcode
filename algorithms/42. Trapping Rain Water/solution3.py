class Solution(object):
    def trap(self, height):
        """
        :type height: List[int]
        :rtype: int
        """
        total = tmp = m = idx = 0
        for i, h in enumerate(height):
            if h >= m:
                m = h
                total += tmp
                tmp = 0
                idx = i
            else:
                tmp += m - h
        tmp = m = 0
        for i in xrange(len(height) - 1, -1, -1):
            if i < idx:
                break
            if height[i] >= m:
                m = height[i]
                total += tmp
                tmp = 0
            else:
                tmp += m - height[i]
        return total
