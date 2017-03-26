class Solution(object):
    def removeBoxes(self, boxes):
        """
        :type boxes: List[int]
        :rtype: int
        """
        def dfs(l, r, k):
            if l >= r:
                return 0
            key = (l, r, k)
            if key not in mem:
                # do some optimize for python
                # reduce branch for duplicate continuous color
                d = r - 1
                while d >= l and boxes[d] == boxes[r-1]:
                    d -= 1
                r, k = d + 1, k + r - 2 - d
                # split [i...j-1] to [i...m][m+1...j-1] where a[m] == a[j]
                p = dfs(l, r, 0) + k ** 2
                for i in xrange(l, r):
                    if boxes[i] == boxes[r]:
                        p = max(p, dfs(l, i + 1, k) + dfs(i + 1, r, 0))
                mem[key] = p
            return mem[key]
        mem = {}
        return dfs(0, len(boxes), 0)
