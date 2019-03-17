func shipWithinDays(weights []int, D int) int {
    var left, right int = 0, 0
    for _, w := range weights {
        if w > left {
            left = w
        }
        right += w
    }
    for ; left <= right; {
        var mid, bucket, cur int = (left + right) / 2, 1, 0
        for _, w := range weights {
            if (w + cur > mid) {
                cur = 0
                bucket++
            }
            cur += w
        }
        if (bucket <= D) {
            right = mid - 1
        } else {
            left = mid + 1
        }
    }
    return left
}
