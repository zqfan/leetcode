class Solution {
public:
    vector<double> calcEquation(vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries) {
        map<string, map<string, double>> g;
        for ( int i = 0, n = equations.size(); i < n; ++i ) {
            string & p = equations[i].first, & q = equations[i].second;
            g[p][p] = g[q][q] = 1.0;
            g[p][q] = values[i];
            g[q][p] = 1.0 / values[i];
        }
        for ( auto & i : g ) {
            for ( auto & j : g ) {
                for ( auto & k : g ) {
                    if ( g[i.first][k.first] && g[k.first][j.first] ) {
                        g[i.first][j.first] = g[i.first][k.first] * g[k.first][j.first];
                    }
                }
            }
        }
        vector<double> result;
        for ( auto & q : queries ) {
            result.push_back(g[q.first][q.second] ? g[q.first][q.second] : -1.0);
        }
        return result;
    }
};
