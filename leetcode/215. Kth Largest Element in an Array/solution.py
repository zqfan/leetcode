class Solution(object):
    def findKthLargest(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        heap = [0] * k
        heap[1:] = nums[:k]
        self.init_min_heap(heap)
        for i in range(k, len(nums)):
            if nums[i] > heap[1]:
                heap[1] = nums[i]
                self.adjust_min_heap(heap, 1)
        return heap[1]

    @staticmethod
    def init_min_heap(heap):
        for i in range(len(heap)/2, 0, -1):
            Solution.adjust_min_heap(heap, i)

    @staticmethod
    def adjust_min_heap(heap, i):
        heap[0] = heap[i]
        j = i * 2
        while j < len(heap):
            if j+1 < len(heap) and heap[j] > heap[j+1]:
                j += 1
            if heap[0] <= heap[j]:
                break
            else:
                heap[j/2] = heap[j]
                j *= 2
        heap[j/2] = heap[0]

# test
s = Solution().findKthLargest
import random
l = [random.randint(-32767, 32767) for i in range(100)]
assert s(l, 1) == sorted(l)[-1]
