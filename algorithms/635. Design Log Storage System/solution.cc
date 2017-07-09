class LogSystem {
    vector<pair<int, string>> log;
    map<string, int> len = {{"Year", 4}, {"Month", 7}, {"Day", 10},
                            {"Hour", 13}, {"Minute", 16}, {"Second", 19}};
public:
    LogSystem() {
    }

    void put(int id, string timestamp) {
        log.push_back({id, timestamp});
    }

    vector<int> retrieve(string s, string e, string gra) {
        int l = len[gra];
        s = s.substr(0, l);
        e = e.substr(0, l);
        vector<int> result;
        for ( auto & p : log ) {
            string ts = p.second.substr(0, l);
            if ( s <= ts && ts <= e )
                result.push_back(p.first);
        }
        return result;
    }
};

/**
 * Your LogSystem object will be instantiated and called as such:
 * LogSystem obj = new LogSystem();
 * obj.put(id,timestamp);
 * vector<int> param_2 = obj.retrieve(s,e,gra);
 */
