class Solution(object):
    def findPairs(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        if k < 0:
            return 0
        nums_set = set()
        pair_set = set()
        for n in nums:
            if n - k in nums_set:
                pair_set.add(n - k)
            if n + k in nums_set:
                pair_set.add(n)
            nums_set.add(n)
        return len(pair_set)
