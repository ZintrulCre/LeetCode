class Solution {
public:
    bool checkRecord(string s) {
        int a = 0, l = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == \u0027L\u0027)
                ++l;
            else
                l = 0;
            if (s[i] == \u0027A\u0027)
                ++a;
            if (a >= 2 || l >= 3)
                return false;
        }
        return true;
    }
};