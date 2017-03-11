class Solution(object):
    def countArrangement(self, N):
        """
        :type N: int
        :rtype: int
        """
        def backtracking(i, remains):
            if not remains:
                arrangement[0] += 1
            for idx, num in enumerate(remains):
                if num % i == 0 or i % num == 0:
                    backtracking(i-1, remains[:idx]+remains[idx+1:])

        arrangement = [0]
        backtracking(N, range(1, N+1))
        return arrangement[0]
