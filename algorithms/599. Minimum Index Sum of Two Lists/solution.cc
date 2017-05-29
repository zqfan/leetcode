class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        unordered_map<string, int> m1, m2;
        for ( int i = 0, n = list1.size(); i < n; ++i ) m1[list1[i]] = i;
        for ( int i = 0, n = list2.size(); i < n; ++i ) m2[list2[i]] = i;
        int m = INT_MAX;
        vector<string> result;
        for ( auto & p : m1 ) {
            if ( m2.find(p.first) != m2.end() ) {
                if ( p.second + m2[p.first] < m ) {
                    m = p.second + m2[p.first];
                    result.clear();
                    result.push_back(p.first);
                } else if ( p.second + m2[p.first] == m ) {
                    result.push_back(p.first);
                }
            }
        }
        return result;
    }
};
