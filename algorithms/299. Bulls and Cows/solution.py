class Solution(object):
    def getHint(self, secret, guess):
        """
        :type secret: str
        :type guess: str
        :rtype: str
        """
        A = sum(i == j for i, j in zip(secret, guess))
        c1 = collections.Counter(secret)
        c2 = collections.Counter(guess)
        B = sum((c1 & c2).values())
        return '%dA%dB' % (A, B - A)
