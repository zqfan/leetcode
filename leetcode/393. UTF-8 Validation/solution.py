class Solution(object):
    def validUtf8(self, data):
        """
        :type data: List[int]
        :rtype: bool
        """
        check = 0
        i = 0
        while i < len(data):
            if check:
                if data[i] & 0xc0 != 0x80:
                    return False
                check -= 1
                i += 1
                continue
            if data[i] & 0x80 == 0:
                check = 0
            elif data[i] & 0xe0 == 0xc0:
                check = 1
            elif data[i] & 0xf0 == 0xe0:
                check = 2
            elif data[i] & 0xf8 == 0xf0:
                check = 3
            else:
                return False
            i += 1
        return check == 0
