class Solution(object):
    def findMinMoves(self, machines):
        """
        :type machines: List[int]
        :rtype: int
        """
        total = sum(machines)
        if total % len(machines):
            return -1
        average = total / len(machines)
        moves = [d - average for d in machines]
        r = s = 0
        for m in moves:
            s += m
            r = max(r, abs(s), m)
        return r
