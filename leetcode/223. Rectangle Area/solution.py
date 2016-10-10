class Solution(object):
    def computeArea(self, A, B, C, D, E, F, G, H):
        """
        :type A: int
        :type B: int
        :type C: int
        :type D: int
        :type E: int
        :type F: int
        :type G: int
        :type H: int
        :rtype: int
        """
        def compute_rect_area(A, B, C, D):
            return (C - A) * (D - B)

        area_p = (C - A) * (D - B)
        area_q = (G - E) * (H - F)

        # I google fhe formula to calculate intersection of two rectangles
        overlap_x = (C - A) + (G - E) - (max(C, G) - min(A, E))
        overlap_y = (D - B) + (H - F) - (max(D, H) - min(B, F))
        if overlap_x > 0 and overlap_y > 0:
            return area_p + area_q - overlap_x * overlap_y
        else:
            return area_p + area_q
