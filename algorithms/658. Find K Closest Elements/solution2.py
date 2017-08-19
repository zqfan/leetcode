class Solution(object):
    def findClosestElements(self, arr, k, x):
        """
        :type arr: List[int]
        :type k: int
        :type x: int
        :rtype: List[int]
        """
        le = [n for n in arr if n <= x]
        gt = [n for n in arr if n > x][::-1]
        d = collections.deque()
        while len(d) < k:
            if le and (not gt or x - le[-1] <= gt[-1] - x):
                d.appendleft(le.pop())
            else:
                d.append(gt.pop())
        return list(d)

# 55 / 55 test cases passed.
# Status: Accepted
# Runtime: 249 ms
# beats 79.62 %
