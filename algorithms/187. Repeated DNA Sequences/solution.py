class Solution(object):
    def findRepeatedDnaSequences(self, s):
        """
        :type s: str
        :rtype: List[str]
        """
        counter = collections.defaultdict(int)
        for i in xrange(10, len(s) + 1):
            counter[s[i-10:i]] += 1
        return [ss for ss in counter if counter[ss] > 1]

# 32 / 32 test cases passed.
# Status: Accepted
# Runtime: 155 ms
# beats 63.38 %
