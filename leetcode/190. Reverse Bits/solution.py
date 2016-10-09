class Solution:
    # @param n, an integer
    # @return an integer
    def reverseBits(self, n):
        n_str = list(bin(n)[:1:-1])
        n_str += ['0'] * (32 - len(n_str))
        return int('0b' + ''.join(n_str), 2)
