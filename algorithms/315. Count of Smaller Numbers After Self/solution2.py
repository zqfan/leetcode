class Solution(object):
    def countSmaller(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        # @StefanPochmann
        def merge_sort(remains):
            middle = len(remains) / 2
            if not middle:
                return remains
            left = merge_sort(remains[:middle])
            right = merge_sort(remains[middle:])
            for i in xrange(len(remains)-1, -1, -1):
                if not right or left and left[-1][1] > right[-1][1]:
                    res[left[-1][0]] += len(right)
                    remains[i] = left.pop()
                else:
                    remains[i] = right.pop()
            return remains
        res = [0] * len(nums)
        merge_sort(list(enumerate(nums)))
        return res

# 16 / 16 test cases passed.
# Status: Accepted
# Runtime: 265 ms
# 50.38%
