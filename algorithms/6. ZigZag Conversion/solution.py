class Solution(object):
    def convert(self, s, numRows):
        """
        :type s: str
        :type numRows: int
        :rtype: str
        """
        if numRows == 1 or numRows >= len(s):
            return s
        matrix, index, direction = [''] * numRows, 0, 1
        for c in s:
            matrix[index] += c
            index += direction
            if index in (0, numRows - 1):
                direction *= -1
        return ''.join(matrix)

# 1158 / 1158 test cases passed.
# Status: Accepted
# Runtime: 112 ms
# beats 74.57 %
