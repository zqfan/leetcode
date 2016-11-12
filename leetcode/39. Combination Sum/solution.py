class Solution(object):
    def combinationSum(self, candidates, target):
        """
        :type candidates: List[int]
        :type target: int
        :rtype: List[List[int]]
        """
        candidates.sort()  # use sorted in real case
        comb_arr = []
        comb = []
        def dfs(start, target):
            if target == 0:
                comb_arr.append(comb[:])
                return
            for i in range(start, len(candidates)):
                if target < candidates[i]:
                    return
                comb.append(candidates[i])
                dfs(i, target-candidates[i])
                comb.pop()
        dfs(0, target)
        return comb_arr
