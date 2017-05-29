class Solution(object):
    def findIntegers(self, num):
        """
        :type num: int
        :rtype: int
        """
        bn = bin(num)[2:]
        l = len(bn)
        # full stores all number without consecutive 1 with width i
        # partial only stores numbers in full which not larger than target
        full, partial = [1] * (l + 2), [1] * (l + 2)
        for i in xrange(l - 1, -1, -1):
            if bn[i] == '0':
                # we have no choice but 0 to have lower numbers
                partial[i] = partial[i + 1]
            else:
                # we have two choices, 0 and 1
                # if we choose 0, then any number with i-1 width will be lower
                partial[i] = full[i + 1]
                # then choose 10
                if i + 1 < l and bn[i + 1] == '1':
                    # we have full lower number with i-2 width
                    partial[i] += full[i + 2]
                else:
                    # we can only have partial of full lower number with i-2 width
                    partial[i] += partial[i + 2]
            # 0xx and 10x
            full[i] = full[i + 1] + full[i + 2]
        return partial[0]
