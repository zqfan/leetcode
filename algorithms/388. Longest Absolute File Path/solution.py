class Solution(object):
    def lengthLongestPath(self, input):
        """
        :type input: str
        :rtype: int
        """
        if not input:
            return 0
        maxlen = curlen = 0; stack = []
        files = input.split('\n')
        for f in files:
            i = 0
            while f[i] == '\t':
                i += 1
            while len(stack) > i:
                curlen -= stack.pop()
            f = f[i:]
            pos = f.find('.')
            if 0 <= pos < len(f) - 1:
                maxlen = max(maxlen, curlen+len(f))
            elif pos == -1:
                stack.append(len(f)+1)
                curlen += stack[-1]
        return maxlen
