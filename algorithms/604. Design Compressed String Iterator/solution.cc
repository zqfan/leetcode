class StringIterator {
    istringstream iss;
    char c;
    int count;
public:
    StringIterator(string compressedString) {
        iss = istringstream(compressedString);
        count = c = 0;
    }

    char next() {
        if ( hasNext() ) {
            --count;
            return c;
        } else {
            return ' ';
        }
    }

    bool hasNext() {
        if ( count == 0 ) {
            iss >> c >> count;
        }
        return count > 0;
    }
};

/**
 * Your StringIterator object will be instantiated and called as such:
 * StringIterator obj = new StringIterator(compressedString);
 * char param_1 = obj.next();
 * bool param_2 = obj.hasNext();
 */
