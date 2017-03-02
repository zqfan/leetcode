cache = {}
class Solution(object):
    def countArrangement(self, N):
        """
        :type N: int
        :rtype: int
        """
        def backtracking(i, remains):
            if not remains:
                return 1
            key = (i, remains)
            if key in cache:
                return cache[key]
            cnt = 0
            for idx, num in enumerate(remains):
                if num % i == 0 or i % num == 0:
                    cnt += backtracking(i - 1, remains[:idx] + remains[idx + 1:])
            return cache.setdefault(key, cnt)

        return backtracking(N, tuple(xrange(1, N+1)))
