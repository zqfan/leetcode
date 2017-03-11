class Solution(object):
    def reverseVowels(self, s):
        """
        :type s: str
        :rtype: str
        """
        vowels = set(['a', 'e', 'i', 'o', 'u',
                      'A', 'E', 'I', 'O', 'U'])
        i, j, slist = 0, len(s) - 1, list(s)
        while i < j:
            if s[i] in vowels and s[j] in vowels:
                slist[i], slist[j] = slist[j], slist[i]
                i += 1
                j -= 1
            elif s[i] in vowels:
                j -= 1
            elif s[j] in vowels:
                i += 1
            else:
                i += 1
                j -= 1
        return ''.join(slist)

# test
s = Solution().reverseVowels
assert s("hello") == "holle"
assert s("leetcode") == "leotcede"
assert s("HELLO") == "HOLLE"
