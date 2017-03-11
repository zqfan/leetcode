class Solution(object):
    def validIPAddress(self, IP):
        """
        :type IP: str
        :rtype: str
        """
        slices = IP.split('.')
        if len(slices) == 4:
            for s in slices:
                if not s.isdigit() or not 0 <= int(s) < 256 or s[0] == '0' and len(s) > 1:
                    return 'Neither'
            return 'IPv4'
        hex_char = set('012345678abcdefABCDEF')
        slices = IP.split(':')
        if len(slices) == 8:
            for s in slices:
                if not s or set(s) - hex_char or len(s) > 4:
                    return 'Neither'
            return 'IPv6'
        return 'Neither'

# 95 / 95 test cases passed.
# Status: Accepted
# Runtime: 39 ms
