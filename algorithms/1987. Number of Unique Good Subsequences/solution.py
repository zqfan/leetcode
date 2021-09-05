class Solution:
    def numberOfUniqueGoodSubsequences(self, binary: str) -> int:
        last0, last1, m = 0, 0, 1000000007
        for c in binary:
            if c == "0":
                last0 = (last0 + last1) % m
            else:
                last1 = (last0 + last1 + 1) % m
        return (last0 + last1 + int("0" in binary)) % m
