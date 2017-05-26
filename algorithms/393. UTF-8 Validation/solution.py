class Solution(object):
    def validUtf8(self, data):
        """
        :type data: List[int]
        :rtype: bool
        """
        follow = 0
        for n in data:
            if follow != 0:
                if n >> 6 != 0b10:
                    return False
                follow -= 1
            elif n >> 5 == 0b110:
                follow = 1
            elif n >> 4 == 0b1110:
                follow = 2
            elif n >> 3 == 0b11110:
                follow = 3
            elif n >> 7:
                return False
        return follow == 0
