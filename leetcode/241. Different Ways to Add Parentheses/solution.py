class Solution(object):
    def diffWaysToCompute(self, input):
        """
        :type input: str
        :rtype: List[int]
        """
        op = {
            '+': operator.add,
            '-': operator.sub,
            '*': operator.mul
        }
        ret = []
        for i, c in enumerate(input):
            if not c.isdigit():
                left = self.diffWaysToCompute(input[:i])
                right = self.diffWaysToCompute(input[i+1:])
                for l in left:
                    for r in right:
                        ret.append(op[input[i]](l, r))
        if not ret and input:
            ret = [int(input)]
        return ret
