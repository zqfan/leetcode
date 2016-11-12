class Solution(object):
    def combinationSum2(self, candidates, target):
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
                comb_arr.append(tuple(comb))
                return
            for i in range(start, len(candidates)):
                if target < candidates[i]:
                    return
                # we can jump over because c[i] is a subset of c[i-1]
                if i > start and candidates[i] == candidates[i-1]:
                    continue
                comb.append(candidates[i])
                dfs(i+1, target-candidates[i])
                comb.pop()
        dfs(0, target)
        return comb_arr
