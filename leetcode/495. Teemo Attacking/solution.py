class Solution(object):
    def findPoisonedDuration(self, timeSeries, duration):
        """
        :type timeSeries: List[int]
        :type duration: int
        :rtype: int
        """
        poisoned_time = duration * len(timeSeries)
        for i in xrange(1, len(timeSeries)):
            overlap = duration - (timeSeries[i] - timeSeries[i-1])
            if overlap > 0:
                poisoned_time -= overlap
        return poisoned_time
