class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        double disx = (double)min(G, C) - max(A, E);
        double disy = (double)min(D, H) - max(B, F);
        int intersect = disx > 0 && disy > 0 ? disx * disy : 0;
        return (G - E) * (H - F) + (D - B) * (C - A) - intersect;
    }
};
