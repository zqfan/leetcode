class Solution(object):
    def numberOfArithmeticSlices(self, A):
        """
        :type A: List[int]
        :rtype: int
        """
        if len(A) < 3:
            return 0
        slices = 0
        i = 0
        while i < len(A) - 2:
            delta = A[i+1] - A[i]
            if A[i+2] - A[i+1] != delta:
                i += 1
                continue
            j = i + 2
            while j < len(A) and A[j] - A[j-1] == delta:
                j += 1
            l = j - i
            slices += (l - 2)  * (l - 1) / 2
            i = j
        return slices
