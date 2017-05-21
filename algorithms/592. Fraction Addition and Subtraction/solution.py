class Solution(object):
    def fractionAddition(self, expression):
        """
        :type expression: str
        :rtype: str
        """
        import fractions
        result = fractions.Fraction(0, 1)
        for m in re.finditer(r"[+-]?\d+/\d+", expression):
            result += fractions.Fraction(m.group(0))
        return "{}/{}".format(result.numerator, result.denominator)
