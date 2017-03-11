class Solution(object):
    def findNthDigit(self, n):
        """
        :type n: int
        :rtype: int
        """
        num_width = 1
        num_count = 9
        while n > (num_width * num_count):
            n -= num_width * num_count
            num_width += 1
            num_count *= 10
        # I should use math.ceil, but I don't want to use import here
        number_offset = n / num_width
        digit_offset = n % num_width
        if digit_offset == 0:
            digit_offset = num_width
            number_offset -= 1
        number = pow(10, num_width - 1) + number_offset
        return int(str(number)[digit_offset - 1])


# test
s = Solution()
assert s.findNthDigit(3) == 3
assert s.findNthDigit(11) == 0
