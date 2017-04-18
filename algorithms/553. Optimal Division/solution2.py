class Solution(object):
    def optimalDivision(self, nums):
        """
        :type nums: List[int]
        :rtype: str
        """
        def dfs(idx):
            if idx in mem:
                return mem[idx]
            maxDiv = reduce(operator.div, nums[:idx], float(nums[0]) ** 2)
            s = '/'.join(map(str, nums[:idx]))
            for i in xrange(idx - 1, 0, -1):
                right = reduce(operator.div, nums[i:idx], float(nums[i]) ** 2)
                curDiv, curS = dfs(i)
                if curDiv / right > maxDiv:
                    maxDiv = curDiv / right
                    if idx - i > 1:
                        s = curS + '/(' + '/'.join(map(str, nums[i:idx])) + ')'
                    else:
                        s = curS + '/' + str(nums[i])
            return mem.setdefault(idx, (maxDiv, s))
        mem = {0: (0.0, '')}
        return dfs(len(nums))[1]
