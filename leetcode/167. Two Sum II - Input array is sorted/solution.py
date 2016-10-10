class Solution(object):
    def twoSum(self, numbers, target):
        """
        :type numbers: List[int]
        :type target: int
        :rtype: List[int]
        """
        for i, n in enumerate(numbers):
            j = self.bin_search_last(numbers, target - n)
            if 0<= j < len(numbers) and i != j:
                return [i+1, j+1]

    @staticmethod
    def bin_search_last(numbers, target):
        left = 0
        right = len(numbers) - 1
        while left < right:
            middle = (left + right + 1) / 2
            if numbers[middle] <= target:
                left = middle
            else:
                right = middle - 1
        return left if numbers[left] == target else -1
