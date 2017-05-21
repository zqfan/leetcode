class FileSystem {
    struct SimpleFile {
        map<string, SimpleFile *> subFiles;
        string name;
        string content;
        bool isFile;
        SimpleFile(string name): isFile(false) { this->name = name; }
    };
    SimpleFile * root;
public:
    FileSystem() {
        root = new SimpleFile("");
    }

    vector<string> split(const string & s, char delim) {
        vector<string> r;
        istringstream ss(s);
        string token;
        while ( getline(ss, token, delim) ) {
            if ( token.size() > 0 ) {
                r.push_back(token);
            }
        }
        return r;
    }

    vector<string> ls(string path) {
        auto cur = root;
        for ( auto & name : split(path, '/') ) {
            cur = cur->subFiles[name];
        }
        if ( cur->isFile ) {
            return {cur->name};
        } else {
            vector<string> files;
            for ( auto & p : cur->subFiles ) {
                files.push_back(p.first);
            }
            sort(files.begin(), files.end());
            return files;
        }
    }

    void mkdir(string path) {
        auto cur = root;
        for ( auto & name : split(path, '/') ) {
            if ( cur->subFiles.find(name) == cur->subFiles.end() ) {
                cur->subFiles[name] = new SimpleFile(name);
            }
            cur = cur->subFiles[name];
        }
    }

    void addContentToFile(string filePath, string content) {
        auto cur = root;
        for ( auto & name : split(filePath, '/') ) {
            if ( cur->subFiles.find(name) == cur->subFiles.end() ) {
                cur->subFiles[name] = new SimpleFile(name);
            }
            cur = cur->subFiles[name];
        }
        cur->isFile = true;
        cur->content += content;
    }

    string readContentFromFile(string filePath) {
        auto cur = root;
        for ( auto & name : split(filePath, '/') ) {
            cur = cur->subFiles[name];
        }
        return cur->content;
    }
};

/**
 * Your FileSystem object will be instantiated and called as such:
 * FileSystem obj = new FileSystem();
 * vector<string> param_1 = obj.ls(path);
 * obj.mkdir(path);
 * obj.addContentToFile(filePath,content);
 * string param_4 = obj.readContentFromFile(filePath);
 */
