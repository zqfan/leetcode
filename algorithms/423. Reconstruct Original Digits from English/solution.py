class Solution(object):
    def originalDigits(self, s):
        """
        :type s: str
        :rtype: str
        """
        digits = ['' ] * 10
        pop_order = [
            ('g', "eight", '8'),
            ('h', "three", '3'),
            ('u', "four", '4'),
            ('f', "five", '5'),
            ('r', "zero", '0'),
            ('t', "two", '2'),
            ('o', "one", '1'),
            ('v', "seven", '7'),
            ('e', "nine", '9'),
            ('s', "six", '6')]
        chr_count = collections.defaultdict(int)
        for c in s:
            chr_count[c] += 1
        for c, word, d in pop_order:
            for w in word:
                if w not in chr_count:
                    break
            else:
                cnt = chr_count[c]
                for w in word:
                    chr_count[w] -= cnt
                    digits[ord(d)-ord('0')] = d * cnt
        return "".join(digits)
