class Solution:
    def bitwiseComplement(self, N: int) -> int:
        x = 1
        while N > x:
            x = (x << 1) + 1
        return x - N
