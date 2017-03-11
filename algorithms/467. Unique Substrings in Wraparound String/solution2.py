class Solution(object):
    def findSubstringInWraproundString(self, p):
        """
        :type p: str
        :rtype: int
        """
        result = 0
        maxlength = collections.defaultdict(int)  # {start_char: max_length}
        i = j = 0
        while i < len(p):
            j += 1
            if j >= len(p) or (ord(p[j]) - ord(p[j-1]) != 1 and (p[j] != 'a' or p[j-1] != 'z')):
                l = j - i
                while i < j and maxlength[p[i]] < l:
                    result += l - maxlength[p[i]]
                    maxlength[p[i]] = l
                    l -= 1
                    i += 1
                i = j
        return result

# 81 / 81 test cases passed.
# Status: Accepted
# Runtime: 119 ms
