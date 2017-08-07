class Solution(object):
    def cheapestJump(self, A, B):
        """
        :type A: List[int]
        :type B: int
        :rtype: List[int]
        """
        dp = [[float('inf'), []] for i in A]
        dp[0] = [A[0], [1]]
        for i in xrange(len(A)):
            for j in xrange(1, min(B+1, len(A)-i)):
                if A[i+j] == -1:
                    continue
                if dp[i][0] + A[i+j] < dp[i+j][0]:
                    dp[i+j] = [dp[i][0] + A[i+j], dp[i][1] + [i+j+1]]
                elif dp[i][0] + A[i+j] == dp[i+j][0]:
                    dp[i+j][1] = min(dp[i+j][1], dp[i][1] + [i+j+1])
        return dp[-1][1]

# 226 / 226 test cases passed.
# Status: Accepted
# Runtime: 219 ms
