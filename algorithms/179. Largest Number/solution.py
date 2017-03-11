class Solution:
    # @param {integer[]} nums
    # @return {string}
    def largestNumber(self, nums):
        def strnumcmp(x, y):
            strx = '%s%s' % (x, y)
            stry = '%s%s' % (y, x)
            for i in xrange(len(strx)):
                if strx[i] != stry[i]:
                    return ord(strx[i]) - ord(stry[i])
            return 0
        strnums = map(str, nums)
        strnums.sort(cmp=strnumcmp, reverse=True)
        return ''.join(strnums).lstrip('0') or '0'
