class Solution(object):
    def lexicalOrder(self, n):
        """
        :type n: int
        :rtype: List[int]
        """
        result = []
        x = 1
        while len(result) < n:
            result.append(x)
            if x * 10 <= n:
                x *= 10
            elif x < n and x % 10 != 9:
                x += 1
            else:
                x = x / 10 + 1
                while x % 10 == 0:
                    x /= 10
        return result

# 26 / 26 test cases passed.
# Status: Accepted
# Runtime: 862 ms
# beats 91.67 %
