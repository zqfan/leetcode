class Solution(object):
    def matrixReshape(self, nums, r, c):
        """
        :type nums: List[List[int]]
        :type r: int
        :type c: int
        :rtype: List[List[int]]
        """
        n, m = len(nums), len(nums[0])
        if n * m != r * c:
            return nums
        result = []
        count = 0
        for i in xrange(n):
            for j in xrange(m):
                if count % c == 0:
                    result.append([])
                count += 1
                result[-1].append(nums[i][j])
        return result

# 56 / 56 test cases passed.
# Status: Accepted
# Runtime: 165 ms
