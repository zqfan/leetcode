class Solution(object):
    def maxRotateFunction(self, A):
        """
        :type A: List[int]
        :rtype: int
        """
        n = len(A)
        rotate_sum = 0
        for i in range(n):
            rotate_sum += i * A[i]
        sum_a = sum(A)
        max_sum = rotate_sum
        for i in range(n - 1):
            rotate_sum = rotate_sum - n * A[n- i - 1] + sum_a
            max_sum = max(rotate_sum, max_sum)
        return max_sum


# test
s = Solution().maxRotateFunction
assert 26 == s([4, 3, 2, 6])
assert 0 == s([])
assert 0 == s([-1])
