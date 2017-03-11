class Solution(object):
    max_p_arr = [1, 1, 1]

    def integerBreak(self, n):
        """
        :type n: int
        :rtype: int
        """
        if n < len(self.max_p_arr):
            return self.max_p_arr[n]

        for i in range(len(self.max_p_arr), n+1):
            self.max_p_arr.append(0)
            for j in range(1, i/2 + 1):
                a = j * (i - j)
                b = j * self.max_p_arr[i-j]
                c = self.max_p_arr[j] * (i - j)
                d = self.max_p_arr[j] * self.max_p_arr[i-j]
                self.max_p_arr[i] = max(self.max_p_arr[i],
                                        max([a, b, c, d]))

        return self.max_p_arr[n]

# test
s = Solution().integerBreak
assert s(10) == 36
