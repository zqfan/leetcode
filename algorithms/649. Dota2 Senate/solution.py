class Solution(object):
    def predictPartyVictory(self, senate):
        """
        :type senate: str
        :rtype: str
        """
        r = collections.deque([i for i, c in enumerate(senate) if c == 'R'])
        d = collections.deque([i for i, c in enumerate(senate) if c == 'D'])
        while r and d:
            ri, di = r.popleft(), d.popleft()
            if ri < di:
                r.append(ri + len(senate))
            else:
                d.append(di + len(senate))
        return "Radiant" if r else "Dire"

# 81 / 81 test cases passed.
# Status: Accepted
# Runtime: 105 ms
# beats 66.93 %
