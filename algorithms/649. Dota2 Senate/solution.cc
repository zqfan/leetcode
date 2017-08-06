class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<int> r, d;
        for ( int i = 0; i < senate.size(); ++i )
            'R' == senate[i] ? r.push(i) : d.push(i);
        while ( r.size() && d.size() ) {
            int ri = r.front(), di = d.front();
            r.pop();
            d.pop();
            if ( ri < di )
                r.push(ri + senate.size());
            else
                d.push(di + senate.size());
        }
        return r.size() ? "Radiant" : "Dire";
    }
};

// 81 / 81 test cases passed.
// Status: Accepted
// Runtime: 9 ms
// beats 52.66 %
