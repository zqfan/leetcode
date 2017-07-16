class Solution(object):
    def solveEquation(self, equation):
        """
        :type equation: str
        :rtype: str
        """
        # @StefanPochmann
        x, a, side = 0, 0, 1
        for eq, sign, num, isx in re.findall(r"(=)|([+-]?)(\d*)(x?)", equation):
            if eq:
                side = -1
            elif isx:
                x += side * int(sign + '1') * int(num or '1')
            elif num:
                a -= side * int(sign + num)
        return "x=%d" % (a / x) if x else "No solution" if a else "Infinite solutions"
