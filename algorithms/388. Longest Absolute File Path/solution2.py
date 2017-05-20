class Solution(object):
    def lengthLongestPath(self, input):
        """
        :type input: str
        :rtype: int
        """
        m = 0
        A = input.split('\n')
        stack = []
        for f in A:
            D = f.split('\t')
            while len(stack) >= len(D):
                stack.pop()
            stack.append(D[-1])
            if len(D[-1].split('.')) > 1:
                m = max(m, len('/'.join(stack)))
        return m

# 25 / 25 test cases passed.
# Status: Accepted
# Runtime: 38 ms
# beats 86.47 %
