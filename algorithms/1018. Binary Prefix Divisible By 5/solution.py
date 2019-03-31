class Solution:
    def prefixesDivBy5(self, A: List[int]) -> List[bool]:
        result, m = [False] * len(A), 0
        for i, bit in enumerate(A):
            m = ((m << 1) + bit) % 5
            result[i] = m == 0
        return result
