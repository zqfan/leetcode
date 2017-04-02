class Solution(object):
    def removeBoxes(self, boxes):
        """
        :type boxes: List[int]
        :rtype: int
        """
        def dfs(l, r, k):
            if l > r:
                return 0
            key = (l, r, k)
            if key not in mem:
                # do some optimize for python
                # reduce branch for duplicate continuous color
                d = r - 1
                while d >= l and boxes[d] == boxes[r]:
                    d -= 1
                r, k = d + 1, k + r - 1 - d
                # split [i...j] to [i...m][m+1...j] where a[m] == a[j]
                p = dfs(l, r - 1, 0) + (k + 1) ** 2
                for i in xrange(l, r):
                    if boxes[i] == boxes[r]:
                        p = max(p, dfs(l, i, k + 1) + dfs(i + 1, r - 1, 0))
                mem[key] = p
            return mem[key]
        mem = {}
        return dfs(0, len(boxes) - 1, 0)
