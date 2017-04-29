class Solution {
public:
    string decodeString(string s) {
        stack<pair<string, int>> st;
        st.push({"", 1});
        int n = 0;
        for ( char c : s ) {
            if ( isdigit(c) ) {
                n = n * 10 + c - '0';
            } else if ( isalpha(c) ) {
                st.top().first.push_back(c);
            } else if ( '[' == c ) {
                st.push({"", n});
                n = 0;
            } else if ( ']' == c ) {
                auto p = st.top();
                st.pop();
                while ( p.second-- > 0 ) {
                    st.top().first += p.first;
                }
            }
        }
        return st.top().first;
    }
};
