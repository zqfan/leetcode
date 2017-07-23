class AutocompleteSystem(object):

    def __init__(self, sentences, times):
        """
        :type sentences: List[str]
        :type times: List[int]
        """
        self._s2time = {s:time for s, time in zip(sentences, times)}
        self._reset()

    def _reset(self):
        self._candidates = self._s2time.keys()
        self._buffer = ""

    def input(self, c):
        """
        :type c: str
        :rtype: List[str]
        """
        if c == '#':
            self._s2time[self._buffer] = self._s2time.get(self._buffer, 0) + 1
            self._reset()
            return []
        self._buffer += c
        self._candidates = filter(lambda s: s.startswith(self._buffer), self._candidates)
        result = []
        for i in xrange(3):
            select = ""
            for s in self._candidates:
                if s not in result:
                    select = s
                    t = self._s2time[s]
                    break
            for s in self._candidates:
                if s in result:
                    continue
                if self._s2time[s] > t or (self._s2time[s] == t and s < select):
                    select = s
                    t = self._s2time[s]
            if select:
                result.append(select)
        return result

# Your AutocompleteSystem object will be instantiated and called as such:
# obj = AutocompleteSystem(sentences, times)
# param_1 = obj.input(c)

# 43 / 43 test cases passed.
# Status: Accepted
# Runtime: 815 ms
# beats 87.65 %
