class Solution(object):
    def fourSumCount(self, A, B, C, D):
        """
        :type A: List[int]
        :type B: List[int]
        :type C: List[int]
        :type D: List[int]
        :rtype: int
        """
        count = 0
        counter = {}
        for i in A:
            for j in B:
                counter[i+j] = counter.get(i+j, 0) + 1
        for i in C:
            for j in D:
                count += counter.get(-(i+j), 0)
        return count
