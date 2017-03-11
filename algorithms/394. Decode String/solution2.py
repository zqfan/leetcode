class Solution(object):
    def decodeString(self, s):
        """
        :type s: str
        :rtype: str
        """
        i = 0
        while i < len(s) and not s[i].isdigit():
            i += 1
        if i == len(s):
            return s
        n_start = i
        while i < len(s) and s[i].isdigit():
            i += 1
        n_end = i
        c = 1
        b_start = i = i + 1
        while i < len(s) and c != 0:
            if s[i] == '[':
                c += 1
            elif s[i] == ']':
                c -= 1
            i += 1
        b_end = i
        sub_s = self.decodeString(s[b_start:b_end-1])
        sub_s *= int(s[n_start:n_end])
        return s[:n_start] + sub_s + self.decodeString(s[b_end:])
