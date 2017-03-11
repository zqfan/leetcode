class Solution(object):
    def decodeString(self, s):
        """
        :type s: str
        :rtype: str
        """
        # refer: http://bookshadow.com/weblog/2016/09/04/leetcode-decode-string/
        str_lvl = collections.defaultdict(str)
        num_lvl = collections.defaultdict(int)
        lvl = 0
        for c in s:
            if c.isdigit():
                num_lvl[lvl] = num_lvl[lvl] * 10 + int(c)
            elif c.isalpha():
                str_lvl[lvl] += c
            elif c == ']':
                str_lvl[lvl-1] += str_lvl[lvl] * num_lvl[lvl-1]
                str_lvl[lvl] = ''
                num_lvl[lvl-1] = 0
                lvl -= 1
            else:
                lvl += 1
        return str_lvl[0]
