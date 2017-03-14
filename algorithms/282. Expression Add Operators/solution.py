class Solution(object):
    def addOperators(self, num, target):
        """
        :type num: str
        :type target: int
        :rtype: List[str]
        """
        def dfs(prefix, remain, curval, lastval):
            if not remain:
                if curval == target:
                    res.append(prefix)
                return
            for i in xrange(1, len(remain) + 1):
                if i > 1 and remain[0] == '0':
                    continue
                l, r, n = remain[:i], remain[i:], int(remain[:i])
                if prefix:
                    dfs(prefix + '+' + l, r, curval + n, n)
                    dfs(prefix + '-' + l, r, curval - n, -n)
                    c = curval - lastval + lastval * n
                    dfs(prefix + '*' + l, r, c, lastval * n)
                else:
                    dfs(l, r, n, n)

        res = []
        dfs('', num, 0, 0)
        return res
