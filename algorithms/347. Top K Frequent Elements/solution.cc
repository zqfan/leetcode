class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> counter;
        for ( int n : nums ) {
            ++counter[n];
        }
        vector<vector<int>> buckets(nums.size() + 1);
        for ( auto & p : counter ) {
            buckets[p.second].push_back(p.first);
        }
        vector<int> topk;
        for ( int i = buckets.size() - 1; i >=0 && topk.size() < k; --i ) {
            // we can use topk.insert(topk.end(), buckets[i].begin(), buckets[i].end())
            // but it might cause topk.size() > k
            for ( int n : buckets[i] ) {
                topk.push_back(n);
                if ( topk.size() >= k ) {
                    break;
                }
            }
        }
        return topk;
    }
};
