class Solution(object):
    def wordsAbbreviation(self, dict):
        """
        :type dict: List[str]
        :rtype: List[str]
        """
        # store max start index for word[i]'s abbreviation
        start = [1] * len(dict)
        for i, w in enumerate(dict):
            # word's length less than 4 doesn't need abbreviation
            if len(w) < 4:
                continue
            for j in xrange(i + 1, len(dict)):
                s = dict[j]
                # different lengths means different abbr
                # different tails means different abbr
                if len(w) != len(s) or w[-1] != s[-1]:
                    continue
                # find first diversity, store it if it is maximum
                for k in xrange(len(w)):
                    if w[k] != s[k]:
                        start[i] = max(start[i], k+1)
                        start[j] = max(start[j], k+1)
                        break
        res = [0] * len(dict)
        for i, w in enumerate(dict):
            # we should at least shorten 2 char
            if len(w) < 4 or start[i] >= len(w) - 2:
                res[i] = w
                continue
            res[i] = w[:start[i]] + str(len(w)-start[i]-1) + w[-1]
        return res
