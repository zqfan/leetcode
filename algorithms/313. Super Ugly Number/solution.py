class Solution(object):
    def nthSuperUglyNumber(self, n, primes):
        """
        :type n: int
        :type primes: List[int]
        :rtype: int
        """
        # refer to StefanPochmann https://leetcode.com/discuss/72763/python-generators-on-a-heap
        uglies = [1]
        def gen_uglies(prime):
            for u in uglies:
                yield u * prime
        new_uglies = heapq.merge(*map(gen_uglies, primes))
        while len(uglies) < n:
            ugly = next(new_uglies)
            if ugly != uglies[-1]:
                uglies.append(ugly)
        return uglies[-1]
