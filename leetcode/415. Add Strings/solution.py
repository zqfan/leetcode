class Solution(object):
    def addStrings(self, num1, num2):
        """
        :type num1: str
        :type num2: str
        :rtype: str
        """
        if len(num1) < len(num2):
            return self.addStrings(num2, num1)

        l = len(num1)
        num2 = '0' * (l - len(num2)) + num2
        sum_str = [0] * (l + 1)
        carry = 0
        for i in range(l):
            d1 = ord(num1[l-1-i]) - ord('0')
            d2 = ord(num2[l-1-i]) - ord('0')
            d3 = d1 + d2 + carry
            sum_str[l-i] = chr(d3 % 10 + ord('0'))
            carry = d3 / 10
            print sum_str
        if carry != 0:
            sum_str[0] = '1'
            return ''.join(sum_str)
        else:
            return ''.join(sum_str[1:])
