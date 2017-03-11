class Solution(object):
    def wordBreak(self, s, wordDict):
        """
        :type s: str
        :type wordDict: Set[str]
        :rtype: List[str]
        """
        solution_arr = []
        solution = []
        # dp[i] means there is a solution for s[i:]
        dp = [1] * (len(s) + 1)
        def dfs(start):
            if start == len(s):
                solution_arr.append(' '.join(solution))
                return
            for i in range(start, len(s)):
                ss = s[start:i+1]
                if ss in wordDict and dp[i+1]:
                    solution.append(ss)
                    before = len(solution_arr)
                    dfs(i+1)
                    if len(solution_arr) == before:
                        dp[i+1] = 0
                    solution.pop()
        dfs(0)
        return solution_arr
