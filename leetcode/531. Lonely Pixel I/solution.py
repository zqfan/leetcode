class Solution(object):
    def findLonelyPixel(self, picture):
        """
        :type picture: List[List[str]]
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
        for i, row in enumerate(picture):
            if row_cnt[i] != 1:
                continue
            for j, col in enumerate(row):
                if col == 'B' and col_cnt[j] == 1:
                    res += 1
        return res
