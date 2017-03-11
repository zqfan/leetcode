class Solution(object):
    def fractionToDecimal(self, numerator, denominator):
        """
        :type numerator: int
        :type denominator: int
        :rtype: str
        """
        if denominator == 0:
            return "NaN"
        neg = numerator * denominator < 0
        # python do negative divide differently to c
        numerator = abs(numerator)
        denominator = abs(denominator)
        fraction = []
        n = numerator % denominator
        # pre stores the n appears before
        # value is index of fraction
        # repeat of n means repeat in fraction
        pre = {}
        while n:
            if n in pre:
                fraction.insert(pre[n], '(')
                fraction.append(')')
                break
            pre[n] = len(fraction)
            fraction.append(str(n * 10 / denominator))
            n = n * 10 % denominator
        s = str(numerator / denominator)
        if fraction:
            s = s + "." + "".join(fraction)
        if neg:
            s = "-" + s
        return s
