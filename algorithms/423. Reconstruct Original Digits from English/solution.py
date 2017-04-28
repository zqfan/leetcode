class Solution(object):
    def originalDigits(self, s):
        """
        :type s: str
        :rtype: str
        """
        result = [''] * 26
        counter = collections.Counter(s)
        unique = [['z', '0', 'zero'], ['w', '2', 'two'],
                  ['u', '4', 'four'], ['o', '1', 'one'],
                  ['r', '3', 'three'], ['f', '5', 'five'],
                  ['x', '6', 'six'], ['s', '7', 'seven'],
                  ['g', '8', 'eight'], ['i', '9', 'nine']]
        for c, d, w in unique:
            n = counter[c]
            result[ord(d) - ord('0')] = d * n
            for cc in w:
                counter[cc] -= n
        return ''.join(result)
