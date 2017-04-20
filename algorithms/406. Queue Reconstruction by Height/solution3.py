class Solution(object):
    def reconstructQueue(self, people):
        """
        :type people: List[List[int]]
        :rtype: List[List[int]]
        """
        heap = [[k, h, i] for i, (h, k) in enumerate(people)]
        ordered_queue = []
        while heap:
            heapq.heapify(heap)
            ordered_queue.append(people[heapq.heappop(heap)[2]])
            for element in heap:
                if ordered_queue[-1][0] >= element[1]:
                    element[0] -= 1
        return ordered_queue

# 37 / 37 test cases passed.
# Status: Accepted
# Runtime: 1585 ms
# beats 1.97%
