class Solution(object):
    def strongPasswordChecker(self, s):
        """
        :type s: str
        :rtype: int
        """
        # based on @zhichenggu
        def miss(low, high):
            return not any(low <= c <= high for c in s)
        # how many char we need to increase due to missing type
        increase = miss('a', 'z') + miss('A', 'Z') + miss('0', '9')
        # how many repeat sub arr we have, indices are len(subarr) % 3
        repeats = [0] * 3
        replace = pre =0
        for i in xrange(len(s)+1):
            if i == len(s) or s[i] != s[pre]:
                l = i - pre
                if l > 2:
                    replace += l / 3
                    repeats[l % 3] += 1
                pre = i
        if len(s) < 6:
            return max(increase, 6 - len(s))
        elif len(s) < 21:
            return max(increase, replace)
        else:
            delete = len(s) - 20
            # to get few change, we should use delete instead of replace
            # for repeat sub arr, if len % 3 == 0, we can delete only
            # one character to have same effect as a single replacement
            replace -= min(delete, repeats[0])
            # if there are more delete available, deal with repeat sub
            # arr with len % 3 == 1, this time we need delete two
            # character to equal with a replacement
            replace -= min(max(0, delete - repeats[0]), 2 * repeats[1]) / 2
            # with all len % 3 == 0 and len % 3 == 1 handled, all repeat
            # sub arr now are len % 3 == 2, now we need to delete
            # three char
            replace -= max(0, delete - repeats[0] - repeats[1] * 2) / 3
            return delete + max(increase, replace)
