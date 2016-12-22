class Solution(object):
    def totalHammingDistance(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        result = 0
        record = [0] * 32
        for i, n in enumerate(nums):
            s = reversed('{:032b}'.format(n))
            for j, char in enumerate(s):
                if char == '1':
                    result += i - record[j]
                    record[j] += 1
                else:
                    result += record[j]
        return result

# 47 / 47 test cases passed.
# Status: Accepted
# Runtime: 682 ms
