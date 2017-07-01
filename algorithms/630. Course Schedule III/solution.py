class Solution(object):
    def scheduleCourse(self, courses):
        """
        :type courses: List[List[int]]
        :rtype: int
        """
        take, last = [], 0
        for t, d in sorted(courses, key=lambda x: x[1]):
            if last + t <= d:
                last += t
                heapq.heappush(take, -t)
            elif t < - take[0]:
                heapq.heappush(take, -t)
                last += heapq.heappop(take) + t
        return len(take)

# 95 / 95 test cases passed.
# tatus: Accepted
# Runtime: 312 ms
