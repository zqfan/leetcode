class Solution(object):
    def findBlackPixel(self, picture, N):
        """
        :type picture: List[List[str]]
        :type N: int
        :rtype: int
        """
        if not picture:
            return 0
        row_cnt, col_cnt = [0] * len(picture), [0] * len(picture[0])
        for i, row in enumerate(picture):
            for j, col in enumerate(row):
                if col == 'B':
                    row_cnt[i] += 1
                    col_cnt[j] += 1
        res = 0
        for j in xrange(len(col_cnt)):
            if col_cnt[j] == N:
                pre = None
                for i in xrange(len(row_cnt)):
                    if picture[i][j] == 'W':
                        continue
                    if row_cnt[i] != N or (pre and pre != picture[i]):
                        break
                    pre = picture[i]
                else:
                    res += N
        return res
