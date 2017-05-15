/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
bool operator < (const Point & p, const Point & q) {
    return tie(p.x, p.y) < tie(q.x, q.y);
}

class Solution {
public:
    vector<Point> outerTrees(vector<Point>& points) {
        sort(points.begin(), points.end());
        vector<Point> lowerhull;
        for ( auto & p : points ) {
            findhull(p, lowerhull);
        }
        reverse(points.begin(), points.end());
        vector<Point> upperhull;
        for ( auto & p : points ) {
            findhull(p, upperhull);
        }
        lowerhull.insert(lowerhull.end(), upperhull.begin(), upperhull.end());
        set<Point> s(lowerhull.begin(), lowerhull.end());
        return vector<Point> (s.begin(), s.end());
    }

    bool clockwise(Point & p, Point & q, Point & r) {
        return (p.x - r.x) * (q.y - r.y) < (p.y - r.y) * (q.x - r.x);
    }

    void findhull(Point & r, vector<Point> & hull) {
        while ( hull.size() > 1 && clockwise(hull[hull.size()-2], hull.back(), r) ) {
            hull.pop_back();
        }
        hull.push_back(r);
    }
};
