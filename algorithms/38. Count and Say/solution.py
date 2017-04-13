class Solution(object):
    def countAndSay(self, n):
        """
        :type n: int
        :rtype: str
        """
        result = "1"
        for _ in xrange(n - 1):
            cur, count = "", 1
            for i in xrange(1, len(result) + 1):
                if i == len(result) or result[i] != result[i-1]:
                    cur += str(count) + result[i-1]
                    count = 1
                else:
                    count += 1
            result = cur
        return result
