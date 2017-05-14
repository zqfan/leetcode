class Solution {
public:
    int distributeCandies(vector<int>& candies) {
        set<int> kinds(candies.begin(), candies.end());
        return min(candies.size() / 2, kinds.size());
    }
};
