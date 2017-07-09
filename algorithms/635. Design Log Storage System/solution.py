import datetime

class LogSystem(object):

    def __init__(self):
        self._log = []

    def put(self, id, timestamp):
        """
        :type id: int
        :type timestamp: str
        :rtype: void
        """
        self._log.append([timestamp, id])

    def retrieve(self, s, e, gra):
        """
        :type s: str
        :type e: str
        :type gra: str
        :rtype: List[int]
        """
        l = {"Year": 4, "Month": 7, "Day": 10, "Hour": 13, "Minute": 16, "Second": 19}[gra]
        s, e = s[:l], e[:l]
        return [id for ts, id in self._log if s <= ts[:l] <= e]

# Your LogSystem object will be instantiated and called as such:
# obj = LogSystem()
# obj.put(id,timestamp)
# param_2 = obj.retrieve(s,e,gra)

# 63 / 63 test cases passed.
# Status: Accepted
# Runtime: 72 ms
