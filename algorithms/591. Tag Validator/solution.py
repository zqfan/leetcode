class Solution(object):
    def isValid(self, code):
        """
        :type code: str
        :rtype: bool
        """
        # @stefanpochmann
        code = re.sub(r"<!\[CDATA\[.*?\]\]>", "c", code)
        pre = None
        while pre != code:
            pre = code
            code = re.sub(r"<([A-Z]{1,9})>[^<]*</\1>", "t", code)
        return code == 't'
