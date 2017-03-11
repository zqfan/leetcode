class Solution(object):
    def PredictTheWinner(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        def dfs(remains):
            if remains not in mem:
                s = sum(remains)
                mem[remains] = max(s - dfs(remains[1:]), s - dfs(remains[:-1]))
            return mem[remains]
        mem = {tuple(): 0}
        return dfs(tuple(nums)) * 2 >= sum(nums)
