class Solution(object):
    def removeInvalidParentheses(self, s):
        """
        :type s: str
        :rtype: List[str]
        """
        # @dietpepsi
        res = []

        def remove(remains, starti, startj, order):
            p = 0
            for i in xrange(starti, len(remains)):
                if remains[i] == order[0]:
                    p += 1
                elif remains[i] == order[1]:
                    p -= 1
                if p < 0:
                    for j in xrange(startj, i+1):
                        if remains[j] == order[1] and (j == startj or remains[j-1] != order[1]):
                            remove(remains[:j]+remains[j+1:], i, j, order)
                    return
            rem_rev = ''.join(reversed(remains))
            if order[0] == '(':
                remove(rem_rev, 0, 0, (')','('))
            else:
                res.append(rem_rev)

        remove(s, 0, 0, ('(',')'))
        return res

# 125 / 125 test cases passed.
# Status: Accepted
# Runtime: 46 ms
# 96.06%
