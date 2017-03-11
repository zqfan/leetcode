class Solution(object):
    def canCross(self, stones):
        """
        :type stones: List[int]
        :rtype: bool
        """
        steps = {stone: set() for stone in stones}
        steps[0].add(1)
        for i in xrange(len(stones)-1):
            for step in steps[stones[i]]:
                target = stones[i] + step
                if target in steps:
                    if target == stones[-1]:
                        return True
                    steps[target].add(step)
                    steps[target].add(step+1)
                    if step - 1 > 0:
                        steps[target].add(step-1)
        return False

# 39 / 39 test cases passed.
# Status: Accepted
# Runtime: 245 ms
# 73.38%
