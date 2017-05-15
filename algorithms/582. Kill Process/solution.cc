class Solution {
public:
    vector<int> killProcess(vector<int>& pid, vector<int>& ppid, int kill) {
        map<int, vector<int>> T;
        for ( int i = 0, n = pid.size(); i < n; ++i ) {
            T[ppid[i]].push_back(pid[i]);
        }
        vector<int> K;
        K.push_back(kill);
        for ( int i = 0; i < K.size(); ++i ) {
            K.insert(K.end(), T[K[i]].begin(), T[K[i]].end());
        }
        return K;
    }
};
