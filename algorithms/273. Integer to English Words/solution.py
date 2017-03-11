class Solution(object):
    def numberToWords(self, num):
        """
        :type num: int
        :rtype: str
        """
        if num == 0:
            return 'Zero'
        res = ''
        w1 = ['', ' One ', ' Two ', ' Three ', ' Four ', ' Five ', ' Six ',
              ' Seven ', ' Eight ', ' Nine ', ' Ten ', ' Eleven ', ' Twelve ',
              ' Thirteen ', ' Fourteen ', ' Fifteen ', ' Sixteen ',
              ' Seventeen ', ' Eighteen ', ' Nineteen ']
        w2 = ['', '', ' Twenty ', ' Thirty ', ' Forty ', ' Fifty ', ' Sixty ',
              ' Seventy ', ' Eighty ', ' Ninety ']
        w3 = [' Trillion ', ' Billion ', ' Million ', ' Thousand ', '']
        while num:
            s = ''
            n = num % 1000
            if n / 100:
                s = w1[n / 100] + ' Hundred '
            n %= 100
            if n < 20:
                s += w1[n]
            else:
                s += w2[n / 10] + w1[n % 10]
            num /= 1000
            if s and not s.isspace():
                s += w3[-1]
            w3.pop()
            res = s + res
        return ' '.join(res.split())
