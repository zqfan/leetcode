class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        unordered_map<int, unordered_set<int>> g;
        vector<int> indegree(numCourses);
        for ( auto & p : prerequisites ) {
            g[p.first].insert(p.second);
            ++indegree[p.second];
        }
        queue<int> zeroIndegree;
        for ( int i = 0; i < numCourses; ++i )
            if ( 0 == indegree[i] )
                zeroIndegree.push(i);
        int count = 0;
        while ( zeroIndegree.size() ) {
            ++count;
            int v = zeroIndegree.front();
            zeroIndegree.pop();
            for ( int u : g[v] )
                if ( --indegree[u] == 0 )
                    zeroIndegree.push(u);
        }
        return count == numCourses;
    }
};

// 37 / 37 test cases passed.
// Status: Accepted
// Runtime: 22 ms
// beats 37.87 %
