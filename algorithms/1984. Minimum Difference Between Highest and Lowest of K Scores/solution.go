func minimumDifference(nums []int, k int) int {
    if k == 1 {
        return 0
    }
    sort.Ints(nums)
    m := 100000
    for i := k - 1; i < len(nums); i++ {
        if m > nums[i] - nums[i-k+1] {
            m = nums[i] - nums[i-k+1]
        }
    }
    return m
}
