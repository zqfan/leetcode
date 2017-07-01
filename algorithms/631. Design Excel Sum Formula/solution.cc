class Excel {
    // if cell u is in the formula for cell v, then dg[u][v] = x, x means the times
    unordered_map<string, unordered_map<string, int>> dg;
    // stores all the cell u for cell v
    unordered_map<string, unordered_set<string>> rdg;
    unordered_map<string, int> cell2val;

    void dfs_update(const string & cell, int val) {
        int diff = val - cell2val[cell];
        for ( auto & p : dg[cell] )
            dfs_update(p.first, cell2val[p.first] + diff * dg[cell][p.first]);
        cell2val[cell] = val;
    }
public:
    Excel(int H, char W) {

    }

    void set(int r, char c, int v) {
        // drop previous relationship in the graph
        string cell = c + to_string(r);
        for ( const string & u : rdg[cell] )
            dg[u].erase(cell);
        rdg.erase(cell);
        // update cell and all its dependent cells
        dfs_update(cell, v);
    }

    int get(int r, char c) {
        return cell2val[c + to_string(r)];
    }

    int sum(int r, char c, vector<string> strs) {
        string cell = c + to_string(r);
        // drop previous relationship in the graph
        for ( const string & u : rdg[cell] )
            dg[u].erase(cell);
        rdg[cell].clear();
        // build new relationship for cells
        int val = 0;
        for ( const string & number : strs ) {
            int pos = number.find(':');
            if ( pos == string::npos ) {
                ++dg[number][cell];
                rdg[cell].insert(number);
                val += cell2val[number];
            } else {  // here we have constraint that col is only one char wide
                string colrow1 = number.substr(0, pos);
                string colrow2 = number.substr(pos + 1);
                char col1 = colrow1[0], col2 = colrow2[0];
                int row1 = stoi(colrow1.substr(1)), row2 = stoi(colrow2.substr(1));
                for ( int row = row1; row <= row2; ++row ) {
                    for ( char col = col1; col <= col2; ++col ) {
                        string colrow = col + to_string(row);
                        ++dg[colrow][cell];
                        rdg[cell].insert(colrow);
                        val += cell2val[colrow];
                    }
                }
            }
        }
        // update cell and its dependant cells
        dfs_update(cell, val);
        return val;
    }
};

/**
 * Your Excel object will be instantiated and called as such:
 * Excel obj = new Excel(H, W);
 * obj.set(r,c,v);
 * int param_2 = obj.get(r,c);
 * int param_3 = obj.sum(r,c,strs);
 */

/*
20 / 20 test cases passed.
Status: Accepted
Runtime: 3 ms
*/
