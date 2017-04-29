class Solution(object):
    def permute(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        def bt(remains):
            if remains in mem:
                return mem[remains]
            p = []
            for i, n in enumerate(remains):
                for x in bt(remains[:i] + remains[i + 1:]):
                    p.append([n] + x)
            return mem.setdefault(remains, p)
        mem = {tuple() : [[]]}
        return bt(tuple(nums))

# 25 / 25 test cases passed.
# Status: Accepted
# Runtime: 93 ms
# beats 29.41 %
