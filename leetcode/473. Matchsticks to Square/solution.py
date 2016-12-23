class Solution(object):
    def makesquare(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        def dfs(remains, target, count):
            if target == 0:
                count += 1
                target = p/4
            if not remains:
                return count == 4 and target == p/4
            if count >= 4 or remains[0] > target:
                return False
            for i, n in enumerate(remains):
                if dfs(remains[:i]+remains[i+1:], target-n, count):
                    return True
            return False

        remains = sorted(nums, reverse=True)
        p = sum(nums)
        if not p or p % 4 != 0:
            return False
        return dfs(remains, p/4, 0)

# 174 / 174 test cases passed.
# Status: Accepted
# Runtime: 136 ms
