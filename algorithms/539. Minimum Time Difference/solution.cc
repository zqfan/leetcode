class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        sort(timePoints.begin(), timePoints.end());
        int minDiff = getDiff(timePoints[0], timePoints.back());
        for ( int i = 1; i < timePoints.size(); ++i ) {
            minDiff = min(minDiff, getDiff(timePoints[i-1], timePoints[i]));
        }
        return minDiff;
    }

    int getDiff(string & t1, string & t2) {
        int h1, m1, h2, m2;
        sscanf(t1.c_str(), "%d:%d", &h1, &m1);
        sscanf(t2.c_str(), "%d:%d", &h2, &m2);
        int diff = (h2 - h1) * 60 + m2 - m1;
        return diff <= 720 ? diff : 1440 - diff;
    }
};
