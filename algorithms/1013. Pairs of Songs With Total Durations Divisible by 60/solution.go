func numPairsDivisibleBy60(time []int) int {
    var counter [60] int
    result := 0
    for _, t := range time {
        result += counter[(60 - t % 60) % 60]
        counter[t % 60]++
    }
    return result
}
