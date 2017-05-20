class Solution(object):
    def lengthLongestPath(self, input):
        """
        :type input: str
        :rtype: int
        """
        # @StefanPochmann
        maxlen = 0
        pathlen = {0: 0}
        for file in input.splitlines():
            name = file.lstrip('\t')
            depth = len(file) - len(name)
            if '.' in name:
                maxlen = max(maxlen, pathlen[depth] + len(name))
            else:
                pathlen[depth + 1] = pathlen[depth] + len(name) + 1
        return maxlen

# 25 / 25 test cases passed.
# Status: Accepted
# Runtime: 58 ms
# beats 15.59 %
