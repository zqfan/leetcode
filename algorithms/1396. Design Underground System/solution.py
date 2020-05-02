class UndergroundSystem(object):

    def __init__(self):
        self._record = {}
        self._onbrd = {}

    def checkIn(self, id, stationName, t):
        """
        :type id: int
        :type stationName: str
        :type t: int
        :rtype: None
        """
        self._onbrd[id] = (stationName, t)

    def checkOut(self, id, stationName, t):
        """
        :type id: int
        :type stationName: str
        :type t: int
        :rtype: None
        """
        k = (self._onbrd[id][0], stationName)
        if k not in self._record:
            self._record[k] = {"sum": 0.0, "cnt": 0}
        self._record[k]["sum"] += t - self._onbrd[id][1]
        self._record[k]["cnt"] += 1
        self._onbrd.pop(id)

    def getAverageTime(self, startStation, endStation):
        """
        :type startStation: str
        :type endStation: str
        :rtype: float
        """
        k = (startStation, endStation)
        return self._record[k]["sum"] / self._record[k]["cnt"]

# Your UndergroundSystem object will be instantiated and called as such:
# obj = UndergroundSystem()
# obj.checkIn(id,stationName,t)
# obj.checkOut(id,stationName,t)
# param_3 = obj.getAverageTime(startStation,endStation)
