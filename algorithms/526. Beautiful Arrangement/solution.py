class Solution(object):
    def countArrangement(self, N):
        """
        :type N: int
        :rtype: int
        """
        def backtracking(i, remains):
            if not remains:
                return 1
            if remains in cache:
                return cache[remains]
            cnt = 0
            for idx, num in enumerate(remains):
                if num % i == 0 or i % num == 0:
                    cnt += backtracking(i - 1, remains[:idx] + remains[idx + 1:])
            return cache.setdefault(remains, cnt)

        cache = {}
        return backtracking(N, tuple(xrange(1, N+1)))

# 15 / 15 test cases passed.
# Status: Accepted
# Runtime: 116 ms
# beats 82.28%
