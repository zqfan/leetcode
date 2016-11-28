class Solution(object):
    def countRangeSum(self, nums, lower, upper):
        """
        :type nums: List[int]
        :type lower: int
        :type upper: int
        :rtype: int
        """
        # @StefanPochmann
        def div_conq(start, stop):
            if stop - start < 2:
                return 0
            mid = (start + stop) / 2
            count = div_conq(start, mid) + div_conq(mid, stop)
            i = j = mid
            for k in xrange(start, mid):
                while i < stop and prefixsum[i]-prefixsum[k] < lower:
                    i += 1
                while j < stop and prefixsum[j]-prefixsum[k] <= upper:
                    j += 1
                count += j - i
            prefixsum[start:stop] = sorted(prefixsum[start:stop])
            return count

        prefixsum = [0]
        for n in nums:
            prefixsum.append(prefixsum[-1] + n)
        return div_conq(0, len(prefixsum))

# 61 / 61 test cases passed.
# Status: Accepted
# Runtime: 212 ms
# 80.31%
