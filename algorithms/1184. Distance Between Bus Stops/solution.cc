class Solution {
public:
    int distanceBetweenBusStops(vector<int>& distance, int start, int destination) {
        if (start > destination) swap(start, destination);
        int clockwise = accumulate(distance.begin() + start, distance.begin() + destination, 0);
        int counterclockwise = accumulate(distance.begin() + destination, distance.end(), 0) + accumulate(distance.begin(), distance.begin() + start, 0) ;
        return min(clockwise, counterclockwise);
    }
};
