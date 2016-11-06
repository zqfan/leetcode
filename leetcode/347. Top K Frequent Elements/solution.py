class Solution(object):
    def topKFrequent(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: List[int]
        """
        num_count = {}
        for n in nums:
            num_count[n] = num_count.get(n, 0) + 1

        heap = [(0, 0)] * (k+1)
        self.init_heap(heap)

        i = 1
        for n, count in num_count.iteritems():
            if count > heap[1][1]:
                heap[1] = (n, count)
                self.adjust_heap(heap, 1)

        return [e[0] for e in heap[1:]]

    @staticmethod
    def init_heap(heap):
        for i in range(len(heap)/2, 0, -1):
            Solution.adjust_heap(heap, i)

    @staticmethod
    def adjust_heap(heap, i):
        heap[0] = heap[i]
        j = i * 2
        while j < len(heap):
            if j+1 < len(heap) and heap[j+1][1] < heap[j][1]:
                j += 1
            if heap[0][1] <= heap[j][1]:
                break
            else:
                heap[j/2] = heap[j]
                j *= 2
        heap[j/2] = heap[0]
