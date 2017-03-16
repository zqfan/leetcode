class Solution(object):
    def findKthNumber(self, n, k):
        """
        :type n: int
        :type k: int
        :rtype: int
        """
        # based on @NathanNi
        def count_num_with_prefix(p, q):
            cnt = 0
            while p <= n:
                cnt += min(n + 1, q) - p
                p, q = p * 10, q * 10
            return cnt

        cur = 1
        k -= 1
        while k > 0:
            cnt = count_num_with_prefix(cur, cur + 1)
            if cnt <= k:
                cur += 1
                k -= cnt
            else:
                cur *= 10
                k -= 1
        return cur
