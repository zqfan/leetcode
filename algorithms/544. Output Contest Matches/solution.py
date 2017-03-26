class Solution(object):
    def findContestMatch(self, n):
        """
        :type n: int
        :rtype: str
        """
        matches = collections.deque(map(str, xrange(1,n+1)))
        next_matches = collections.deque()
        while len(matches) > 1:
            while matches:
                next_matches.append('(' + matches.popleft() + ',' + matches.pop() + ')')
            matches, next_matches = next_matches, matches
        return matches[0]
