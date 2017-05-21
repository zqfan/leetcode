class FileSystem(object):

    def __init__(self):
        self.root = {}

    def ls(self, path):
        """
        :type path: str
        :rtype: List[str]
        """
        if path == '/':
            return sorted(self.root.iterkeys())
        P = path.split('/')[1:]
        d = self.root
        for p in P:
            d = d[p]
        return sorted(d.iterkeys()) if isinstance(d, dict) else [P[-1]]

    def mkdir(self, path):
        """
        :type path: str
        :rtype: void
        """
        d = self.root
        for p in path.split('/')[1:]:
            if p not in d:
                d[p] = {}
            d = d[p]

    def addContentToFile(self, filePath, content):
        """
        :type filePath: str
        :type content: str
        :rtype: void
        """
        P = filePath.split('/')[1:]
        d = self.root
        for p in P[:-1]:
            d = d[p]
        if P[-1] not in d:
            d[P[-1]] = ''
        d[P[-1]] += content

    def readContentFromFile(self, filePath):
        """
        :type filePath: str
        :rtype: str
        """
        d = self.root
        for p in filePath.split('/')[1:]:
            d = d[p]
        return d


# Your FileSystem object will be instantiated and called as such:
# obj = FileSystem()
# param_1 = obj.ls(path)
# obj.mkdir(path)
# obj.addContentToFile(filePath,content)
# param_4 = obj.readContentFromFile(filePath)
