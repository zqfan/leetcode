class Solution(object):
    def validSquare(self, p1, p2, p3, p4):
        """
        :type p1: List[int]
        :type p2: List[int]
        :type p3: List[int]
        :type p4: List[int]
        :rtype: bool
        """
        def D((P, Q)):
            return (P[0] - Q[0]) ** 2 + (P[1] - Q[1]) ** 2
        S = set(map(D, itertools.combinations((p1, p2, p3, p4), 2)))
        return len(S) == 2 and 0 not in S

# 244 / 244 test cases passed.
# Status: Accepted
# Runtime: 55 ms
