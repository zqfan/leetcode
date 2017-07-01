class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        auto cmp = [](vector<int> & x, vector<int> & y) { return x[1] < y[1]; };
        sort(courses.begin(), courses.end(), cmp);
        priority_queue<int> take;
        int last = 0;
        for ( auto && c : courses ) {
            if ( c[0] + last <= c[1] ) {
                last += c[0];
                take.push(c[0]);
            } else if ( c[0] < take.top() ) {
                last += c[0] - take.top();
                take.pop();
                take.push(c[0]);
            }
        }
        return take.size();
    }
};

// 95 / 95 test cases passed.
// tatus: Accepted
// Runtime: 142 ms
