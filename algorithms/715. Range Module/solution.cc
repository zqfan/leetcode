class RangeModule {
    vector<int> numbers;
    vector<bool> track;

public:
    RangeModule() {
        numbers = {0, 1000000000};
        track = {false, false};
    }
    
    void addRange(int left, int right) {
        _mark(left, right, true);
    }
    
    bool queryRange(int left, int right) {
        int p1 = upper_bound(numbers.begin(), numbers.end(), left) - numbers.begin() - 1;
        int p2 = lower_bound(numbers.begin(), numbers.end(), right) - numbers.begin();
        if ( p1 < 0 || p1 >= p2 )
            return false;
        for ( int i = p1; i < p2; ++i )
            if ( false == track[i] )
                return false;
        return true;
    }
    
    void removeRange(int left, int right) {
        _mark(left, right, false);
    }

private:
    void _mark(int left, int right, bool isTrack) {
        int i = _index(left);
        int j = _index(right);
        numbers.erase(numbers.begin() + i + 1, numbers.begin() + j);
        numbers[i] = left;
        track.erase(track.begin() + i + 1, track.begin() + j);
        track[i] = isTrack;
    }

    int _index(int num) {
        int p = lower_bound(numbers.begin(), numbers.end(), num) - numbers.begin();
        if ( numbers[p] != num ) {
            numbers.insert(numbers.begin() + p, num);
            track.insert(track.begin() + p, track[p-1]);
        }
        return p;
    }
};

/**
 * Your RangeModule object will be instantiated and called as such:
 * RangeModule obj = new RangeModule();
 * obj.addRange(left,right);
 * bool param_2 = obj.queryRange(left,right);
 * obj.removeRange(left,right);
 */

// 53 / 53 test cases passed.
// Status: Accepted
// Runtime: 385 ms
