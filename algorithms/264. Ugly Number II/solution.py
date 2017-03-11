class Solution(object):
    def nthUglyNumber(self, n):
        """
        :type n: int
        :rtype: int
        """
        l2 = collections.deque([2])
        l3 = collections.deque([3])
        l5 = collections.deque([5])
        cur = 1
        while n > 1:
            min_num, l = min((l2[0], l2), (l3[0], l3), (l5[0], l5))
            if min_num != cur:
                n -= 1
                cur = min_num
                l2.append(cur * 2)
                l3.append(cur * 3)
                l5.append(cur * 5)
            l.popleft()
        return cur
