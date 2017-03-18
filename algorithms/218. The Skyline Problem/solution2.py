class Solution(object):
    def getSkyline(self, buildings):
        """
        :type buildings: List[List[int]]
        :rtype: List[List[int]]
        """
        # @StefanPochmann
        l = len(buildings)
        # store all buildings which left sides have been processed
        # while right ends are undetermined, sorting by height then
        # right end.
        rightends = []
        skyline = []
        i = 0
        while i < l or rightends:
            # if new building's left side cannot be determined because
            # it might be covered by higher left buildings,
            # we push it to the heap, then calculate height later.
            #
            # if the hight is current value, means it is not covered and
            # we need to append a new left side,
            # otherwise it is covered by left buildings, and the hight will
            # be same as previous, so we skip it.
            #
            # when the left equal to left highest right end, we treat it
            # as potential covered as well.
            if not rightends or i < l and buildings[i][0] <= -rightends[0][1]:
                x = buildings[i][0]
                # same left side should has only one point, just like
                # same height case.
                while i < l and buildings[i][0] == x:
                    end = (-buildings[i][2], -buildings[i][1])
                    heapq.heappush(rightends, end)
                    i += 1
            # if new building's left side definitely will not be covered
            # by left highest building, we need to check if it is covered
            # by next high building, so we need to process highest right
            # end.
            else:
                x = -rightends[0][1]
                # skip all right ends which covered by highest end
                while rightends and -rightends[0][1] <= x:
                    heapq.heappop(rightends)
            h = -rightends[0][0] if rightends else 0
            if not skyline or h != skyline[-1][1]:
                skyline.append([x, h])
        return skyline
