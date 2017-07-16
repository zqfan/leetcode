class Solution(object):
    def solveEquation(self, equation):
        """
        :type equation: str
        :rtype: str
        """
        # @StefanPochmann
        e = eval(equation.replace("x", "j").replace("=", "-(") + ")", {"j": 1j})
        a, x = e.real, -e.imag
        return "x=%d" % (a / x) if x else "No solution" if a else "Infinite solutions"
