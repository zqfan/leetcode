func bitwiseComplement(N int) int {
    x := 1
    for ; x < N; {
        x = (x << 1) + 1
    }
    return x - N
}
