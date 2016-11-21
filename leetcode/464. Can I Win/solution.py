class Solution(object):
    def canIWin(self, maxChoosableInteger, desiredTotal):
        """
        :type maxChoosableInteger: int
        :type desiredTotal: int
        :rtype: bool
        """
        n = maxChoosableInteger; t = desiredTotal
        s = (1 + n) * n / 2
        if t > s:
            return False
        flag = {}
        def dfs(nums, t):
            if nums in flag:
                return flag[nums]
            if nums[-1] >= t:
                flag[nums] = True
                return True
            for i in xrange(len(nums)):
                if not dfs(nums[:i]+nums[i+1:], t-nums[i]):
                    flag[nums] = True
                    return True
            flag[nums] = False
            return False
        return dfs(tuple(xrange(1, n+1)), t)
