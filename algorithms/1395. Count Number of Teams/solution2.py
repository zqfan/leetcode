class Solution(object):
    def numTeams(self, rating):
        """
        :type rating: List[int]
        :rtype: int
        """
        l3asc = [0] * len(rating)
        l3desc = [0] * len(rating)
        l2asc = [0] * len(rating)
        l2desc = [0] * len(rating)
        for i, n in enumerate(rating):
            for j in xrange(0, i):
                if rating[i] > rating[j]:
                    l2asc[i] += 1
                    l3asc[i] += l2asc[j]
                elif rating[i] < rating[j]:
                    l2desc[i] += 1
                    l3desc[i] += l2desc[j]
        return sum(l3asc) + sum(l3desc)
