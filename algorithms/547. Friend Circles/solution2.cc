class UnionFind {
    int count;
    vector<int> root;
    vector<int> rank;
public:
    UnionFind(int n) {
        count = n;
        for ( int i = 0; i < n; i++ ){
            root.push_back(i);
            rank.push_back(0);
        }
    }

    int find(int p) {
        while ( p != root[p] ) {
            root[p] = root[root[p]];
            p = root[p];
        }
        return p;
    }

    void merge(int p, int q) {
        int rootp = find(p);
        int rootq = find(q);
        if ( rootp == rootq ) {
            return;
        }
        if ( rank[rootq] > rank[rootp] ) {
            root[rootp] = rootq;
        } else {
            root[rootq] = rootp;
            if ( rank[rootp] == rank[rootq] ) {
                ++rank[rootp];
            }
        }
        --count;
    }

    int getCount() {
        return count;
    }
};

class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        UnionFind uf(M.size());
        for ( int i = 0; i < M.size(); ++i ) {
            for ( int j = i + 1; j < M.size(); ++j ) {
                if ( M[i][j] ) {
                    uf.merge(i, j);
                }
            }
        }
        return uf.getCount();
    }
};
