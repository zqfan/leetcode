class Solution(object):
    def frequencySort(self, s):
        """
        :type s: str
        :rtype: str
        """
        c_count = {}
        for c in s:
            c_count[c] = c_count.get(c, 0) + 1

        self.heap_len = len(c_count) + 1
        self.heap = [(0, 0)] * self.heap_len
        for i, cc in enumerate(c_count.iteritems()):
            self.heap[i+1] = cc
        self.init_heap()

        c_arr = [0] * len(s)
        i = 0
        while self.heap_len > 1:
            c, count = self.pop_heap()
            for j in range(count):
                c_arr[i] = c
                i += 1

        return ''.join(c_arr)

    def init_heap(self):
        for i in range(self.heap_len/2, 0, -1):
            self.adjust_heap(i)

    def pop_heap(self):
        self.heap_len -= 1
        t = self.heap[1]
        self.heap[1] = self.heap[self.heap_len]
        self.heap[self.heap_len] = (0, 0)
        self.adjust_heap(1)
        return t

    def adjust_heap(self, i):
        self.heap[0] = self.heap[i]
        j = i * 2
        while j < self.heap_len:
            if j+1 < self.heap_len and self.heap[j+1][1] > self.heap[j][1]:
                j += 1
            if self.heap[0][1] >= self.heap[j][1]:
                break
            else:
                self.heap[j/2] = self.heap[j]
                j *= 2
        self.heap[j/2] = self.heap[0]

# test
s = Solution().frequencySort
print s("tree")
