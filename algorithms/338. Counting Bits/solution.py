class Solution(object):
    def countBits(self, num):
        """
        :type num: int
        :rtype: List[int]
        """
        if num == 0:
            return [0]
        bits = [0] * (num + 1)
        pow2i = 0
        for i in range(num):
            pow2i = pow(2, i)
            if pow2i > num/2:
                break
            for j in range(pow2i):
                bits[j+pow2i] = bits[j] + 1
        for i in range(pow2i, num + 1):
            bits[i] = bits[i-pow2i] + 1
        return bits
