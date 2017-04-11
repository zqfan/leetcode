class Solution(object):
    def repeatedSubstringPattern(self, str):
        """
        :type str: str
        :rtype: bool
        """
        counter = {}
        for c in str:
            counter[c] = counter.get(c, 0) + 1
        values = counter.values()
        gcd = values[0]
        for v in values:
            while v % gcd != 0:
                v, gcd = gcd, v % gcd
        if gcd == 1:
            return False
        for c in counter:
            counter[c] /= gcd
        length = sum(counter.values())
        step = length
        while step <= len(str)/2:
            for j in range(step, len(str), step):
                for k in reversed(range(step)):
                    if str[k] != str[j+k]:
                        break
                else:
                    continue
                break
            else:
                return True
            if j == step:
                step += length
            else:
                step = ((j+k) / length + 1) * length
        return False
