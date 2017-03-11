class Solution(object):
    def find132pattern(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        if not nums:
            return False
        peaks = [[nums[0], nums[0]]]
        for n in nums:
            if peaks[-1][0] < n < peaks[-1][1]:
                return True
            elif n >= peaks[-1][1]:
                peaks[-1][1] = n
                while len(peaks) > 1 and peaks[-2][1] <= n:
                    peaks[-2][0] = peaks[-1][0]
                    peaks[-2][1] = n
                    peaks.pop()
                if len(peaks) > 1 and n > peaks[-2][0]:
                    return True
            else:
                peaks.append([n, n])
        return False
