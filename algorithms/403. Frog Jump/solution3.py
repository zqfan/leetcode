ass Solution(object):
    def canCross(self, stones):
        """
        :type stones: List[int]
        :rtype: bool
        """
        dp = [set() for _ in xrange(len(stones))]
        dp[0].add(1)
        for i in xrange(len(stones)-1):
            for step in dp[i]:
                target = stones[i] + step
                idx = bisect.bisect_left(stones, target, lo=i+1)
                if idx != len(stones) and stones[idx] == target:
                    if idx == len(stones) - 1:
                        return True
                    dp[idx].add(step)
                    dp[idx].add(step+1)
                    if step - 1 > 0:
                        dp[idx].add(step-1)
        return False

# 39 / 39 test cases passed.
# Status: Accepted
# Runtime: 486 ms
# 24.13%
