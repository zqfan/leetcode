class Solution(object):
    def twoSum(self, numbers, target):
        """
        :type numbers: List[int]
        :type target: int
        :rtype: List[int]
        """
        for i in xrange(len(numbers)):
            j = bisect.bisect_left(numbers, target - numbers[i], i + 1)
            if j < len(numbers) and numbers[j] == target - numbers[i]:
                return [i + 1, j + 1]
