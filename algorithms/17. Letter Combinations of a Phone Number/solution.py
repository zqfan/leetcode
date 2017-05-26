class Solution(object):
    def letterCombinations(self, digits):
        """
        :type digits: str
        :rtype: List[str]
        """
        m = [" ", "*", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"]
        res = collections.deque()
        res.append('')
        for d in digits:
            for i in xrange(len(res)):
                s = res.popleft()
                for c in m[ord(d) - ord('0')]:
                    res.append(s + c)
        return list(res) if digits else []
