class Solution(object):
    def distributeCandies(self, candies):
        """
        :type candies: List[int]
        :rtype: int
        """
        visited = set()
        sister = brother = dup = 0
        for c in candies:
            if c in visited and sister > brother:
                brother += 1
            else:
                if c in visited:
                    dup += 1
                else:
                    visited.add(c)
                sister += 1
        dup = dup - (sister - brother) / 2
        return len(visited) + min(0, dup)
