class Solution(object):
    def getSkyline(self, buildings):
        """
        :type buildings: List[List[int]]
        :rtype: List[List[int]]
        """
        def divide_conquer(start, end):
            if start == end:
                return [[buildings[start][0], buildings[start][2]],
                        [buildings[start][1], 0]]
            mid = (start + end) / 2
            left = divide_conquer(start, mid)
            right = divide_conquer(mid + 1, end)
            r = []
            i = j = h1 = h2 = 0
            while i < len(left) and j < len(right):
                x = min(left[i][0], right[j][0])
                if left[i][0] < right[j][0]:
                    h1 = left[i][1]
                    i += 1
                elif left[i][0] > right[j][0]:
                    h2 = right[j][1]
                    j += 1
                else:
                    h1 = left[i][1]
                    h2 = right[j][1]
                    i += 1
                    j += 1
                h = max(h1, h2)
                if not r or r[-1][1] != h:
                    r.append([x, h])
            r.extend(left[i:])
            r.extend(right[j:])
            return r

        return divide_conquer(0, len(buildings) - 1) if buildings else []
