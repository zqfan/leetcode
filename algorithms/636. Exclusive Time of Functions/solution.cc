class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> result(n);
        stack<int> s;
        char typestr[10];
        int fnid, time, last_time = 0;
        for ( string & log : logs ) {
            sscanf(log.c_str(), "%d:%[^:]:%d", &fnid, typestr, &time);
            if ( 's' == typestr[0] ) {
                if ( s.size() > 0 )
                    result[s.top()] += time - last_time;
                s.push(fnid);
            } else {
                result[s.top()] += ++time - last_time;
                s.pop();
            }
            last_time = time;
        }
        return result;
    }
};

// 120 / 120 test cases passed.
// Status: Accepted
// Runtime: 45 ms
