class Excel(object):

    def __init__(self, H, W):
        """
        :type H: int
        :type W: str
        """
        self.cell2val = collections.defaultdict(int)
        # if u is in formula of v, {u: {v: times}}
        self.dg = collections.defaultdict(lambda: collections.defaultdict(int))
        self.rdg = {}

    def set(self, r, c, v):
        """
        :type r: int
        :type c: str
        :type v: int
        :rtype: void
        """
        cell = c + str(r)
        for c in self.rdg.get(cell, []):
            self.dg[c].pop(cell)
        self.rdg.pop(cell, None)
        self._dfs_update(cell, v)

    def _dfs_update(self, cell, v):
        diff = v - self.cell2val[cell]
        for c in self.dg.get(cell, []):
            self._dfs_update(c, self.cell2val[c] + diff * self.dg[cell][c])
        self.cell2val[cell] = v

    def get(self, r, c):
        """
        :type r: int
        :type c: str
        :rtype: int
        """
        return self.cell2val[c + str(r)]

    def sum(self, r, c, strs):
        """
        :type r: int
        :type c: str
        :type strs: List[str]
        :rtype: int
        """
        cell = c + str(r)
        for c in self.rdg.get(cell, []):
            self.dg[c].pop(cell)
        self.rdg[cell] = set()
        val = 0
        for number in strs:
            if number.find(':') == -1:
                self.dg[number][cell] += 1
                self.rdg[cell].add(number)
                val += self.cell2val[number]
            else:
                colrow1, colrow2 = number.split(':')
                col1, row1 = colrow1[0], int(colrow1[1:])
                col2, row2 = colrow2[0], int(colrow2[1:])
                for col in xrange(ord(col1), ord(col2) + 1):
                    for row in xrange(row1, row2 + 1):
                        colrow = chr(col) + str(row)
                        self.dg[colrow][cell] += 1
                        self.rdg[cell].add(colrow)
                        val += self.cell2val[colrow]

        self._dfs_update(cell, val)
        return val


# Your Excel object will be instantiated and called as such:
# obj = Excel(H, W)
# obj.set(r,c,v)
# param_2 = obj.get(r,c)
# param_3 = obj.sum(r,c,strs)

# 20 / 20 test cases passed.
# Status: Accepted
# Runtime: 39 ms
# beats 87.34 %
