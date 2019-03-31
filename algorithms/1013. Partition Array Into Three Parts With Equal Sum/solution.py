class Solution:
    def canThreePartsEqualSum(self, A: List[int]) -> bool:
        total, cur, counter = sum(A), 0, 0
        if total % 3 != 0:
            return False
        for n in A:
            cur += n
            if cur == total / 3:
                counter += 1
                if counter == 3:
                    return True
                cur = 0
        return False
