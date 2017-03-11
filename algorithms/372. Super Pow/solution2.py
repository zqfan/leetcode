class Solution(object):
    def superPow(self, a, b):
        """
        :type a: int
        :type b: List[int]
        :rtype: int
        """
        # phi(1137) = phi(7) * phi(191) = 1140
        # https://en.wikipedia.org/wiki/Euler%27s_theorem
        a %= 1337
        if a == 0 or a == 1:
            return a
        p = 0
        for n in b:
            p = (p * 10 + n) % 1140
        p = p or 1140
        res = 1
        while p:
            if p & 1:
                res = res * a % 1337
            a = a * a % 1337
            p >>= 1
        return res
