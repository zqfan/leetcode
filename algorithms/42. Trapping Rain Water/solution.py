class Solution(object):
    def trap(self, height):
        """
        :type height: List[int]
        :rtype: int
        """
        total, leftmax, rightmax, left, right = 0, 0, 0, 0, len(height) - 1
        while left <= right:
            leftmax = max(leftmax, height[left])
            rightmax = max(rightmax, height[right])
            if leftmax < rightmax:
                total += leftmax - height[left]
                left += 1
            else:
                total += rightmax - height[right]
                right -= 1
        return total
