class Solution(object):
    def combinationSum3(self, k, n):
        """
        :type k: int
        :type n: int
        :rtype: List[List[int]]
        """
        comb_arr = []
        comb = []
        def dfs(s, n):
            if len(comb) >= k:
                if n == 0:
                    comb_arr.append(comb[:])
                return
            for i in range(s, 10):
                if n < i:
                    return
                comb.append(i)
                dfs(i+1, n-i)
                comb.pop()
        dfs(1, n)
        return comb_arr
