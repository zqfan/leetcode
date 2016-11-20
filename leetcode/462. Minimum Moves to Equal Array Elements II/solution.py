class Solution(object):
    def minMoves2(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        def get_kth(start, stop, k):
            if stop - start < 2:
                return nums[start]
            p = nums[random.randrange(start, stop)]
            e = u = start
            g = stop
            while u < g:
                if nums[u] < p:
                    nums[e], nums[u] = nums[u], nums[e]
                    e += 1
                    u += 1
                elif nums[u] > p:
                    g -= 1
                    nums[u], nums[g] = nums[g], nums[u]
                else:
                    u += 1
            if k <= e-start:
                return get_kth(start, e, k)
            elif k > g-start:
                return get_kth(g, stop, k-g+start)
            else:
                return p
        median = get_kth(0, len(nums), (len(nums)+1)/2)
        return sum(map(lambda x: abs(median-x), nums))
