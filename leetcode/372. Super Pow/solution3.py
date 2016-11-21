class Solution(object):
    def superPow(self, a, b):
        """
        :type a: int
        :type b: List[int]
        :rtype: int
        """
        MOD = 1337; a %= MOD
        if a == 0 or a == 1:
            return a

        def quick_pow(a, b):
            r = 1
            while b > 0:
                if b & 1:
                    r = r * a % MOD
                a = a * a % MOD
                b >>= 1
            return r

        res = 1
        for n in reversed(b):
            res = res * quick_pow(a, n) % MOD
            a = quick_pow(a, 10)
        return res
