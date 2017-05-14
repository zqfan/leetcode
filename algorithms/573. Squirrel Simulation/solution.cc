class Solution {
public:
    int minDistance(int height, int width, vector<int>& tree, vector<int>& squirrel, vector<vector<int>>& nuts) {
        int totalMoves = 0, saveMoves = INT_MIN, move2tree, move2squirrel;
        for ( auto & p : nuts ) {
            move2tree = abs(p[0] - tree[0]) + abs(p[1] - tree[1]);
            totalMoves += 2 * move2tree;
            move2squirrel = abs(p[0] - squirrel[0]) + abs(p[1] - squirrel[1]);
            saveMoves = max(saveMoves, move2tree - move2squirrel);
        }
        return totalMoves - saveMoves;
    }
};
