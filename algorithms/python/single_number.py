class Solution:
    # @param A, a list of integer
    # @return an integer
    def singleNumber(self, A):
        if not A:
            return
        single = 0
        for i in A:
            # a xor 0 = a
            # a xor a = 0
            # (a xor b) xor c == a xor (b xor c)
            # a xor b xor a = b
            single ^= i
        return single
