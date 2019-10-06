class Solution {
public:
    int maxNumberOfBalloons(string text) {
        vector<int> counter(26);
        for (char c: text) {
            ++counter[c - 'a'];
        }
        int res = counter['b' - 'a'];
        res = min(res, counter['a' - 'a']);
        res = min(res, counter['l' - 'a'] / 2);
        res = min(res, counter['o' - 'a'] / 2);
        res = min(res, counter['n' - 'a']);
        return res;
    }
};
