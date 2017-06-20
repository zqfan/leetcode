class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int result = 0;
        map<int, int> starts;
        for ( auto && A : arrays )
            ++starts[A[0]];
        for ( auto && A : arrays ) {
            if ( --starts[A[0]] == 0 )
                starts.erase(A[0]);
            result = max(result, abs(A[0] - starts.begin()->first));
            result = max(result, abs(A.back() - starts.begin()->first));
            ++starts[A[0]];
        }
        return result;
    }
};
