class Solution {
public:
    bool isPossible(vector<int>& nums) {
        map<int, priority_queue<int, vector<int>, greater<int>>> m;
        for ( int n : nums ) {
            while ( m.size() && m.begin()->first + 1 < n ) {
                if ( m.begin()->second.top() < 3 )
                    return false;
                m.erase(m.begin());
            }
            if ( m.empty() || m.begin()->first == n ) {
                m[n].push(1);
            } else {
                m[n].push(m[n-1].top() + 1);
                m[n-1].pop();
                if ( m[n-1].empty() )
                    m.erase(n-1);
            }
        }
        for ( auto & p : m )
            if ( p.second.size() && p.second.top() < 3 )
                return false;
        return true;
    }
};

// 180 / 180 test cases passed.
// Status: Accepted
// Runtime: 86 ms
// beats 92.83 %
