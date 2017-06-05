class Solution(object):
    def canPlaceFlowers(self, flowerbed, n):
        """
        :type flowerbed: List[int]
        :type n: int
        :rtype: bool
        """
        zero = 1  # initial has no left limit
        for slot in flowerbed:
            if slot == 0:
                zero += 1
            else:
                n -= (zero - 1) / 2 if zero else 0
                zero = 0
        n -= zero / 2  # last has no right limit
        return n <= 0
