class Solution:
    def shipWithinDays(self, weights: List[int], D: int) -> int:
        left, right = max(weights), sum(weights)
        while left <= right:
            mid, bucket, cur = (left + right) // 2, 1, 0
            for w in weights:
                if w + cur > mid:
                    cur = 0
                    bucket += 1
                cur += w
            if bucket <= D:
                right = mid - 1
            else:
                left = mid + 1
        return left
