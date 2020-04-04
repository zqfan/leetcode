class Solution(object):
    def numTeams(self, rating):
        """
        :type rating: List[int]
        :rtype: int
        """
        cnt = 0
	# learn from votrubac
        # less_left * bigger_right + less_right * bigger_left
        for i, n in enumerate(rating):
            less, bigger = [0] * 2, [0] * 2
            for j in xrange(len(rating)):
                # rating value is unique
                if rating[j] > rating[i]:
                    less[i < j] += 1
                elif rating[j] < rating[i]:
                    bigger[i < j] += 1
            cnt += less[0] * bigger[1] + less[1] * bigger[0]
        return cnt

# Runtime: 60 ms, faster than 84.74% of Python online submissions for Count Number of Teams.
# Memory Usage: 12.6 MB, less than 100.00% of Python online submissions for Count Number of Teams.
