class Solution:
    def distanceBetweenBusStops(self, distance: List[int], start: int, destination: int) -> int:
        l, r = min(start, destination), max(start, destination)
        return min(sum(distance[l:r]), sum(distance[:l]) + sum(distance[r:]))
