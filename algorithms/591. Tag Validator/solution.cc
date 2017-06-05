class Solution {
public:
    bool isValid(string code) {
        // inspired by stefanpochmann
        regex cdata("<!\\[CDATA\\[.*?\\]\\]>"), tag("<([A-Z]{1,9})>[^<]*</\\1>");
        code = regex_replace(code, cdata, "c");
        string pre = code;
        while ( pre != (code = regex_replace(code, tag, "t")) ) pre = code;
        return "t" == code;
    }
};
