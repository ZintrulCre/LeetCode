class Solution {
public:
    int lengthOfLastWord(string s) {
        int len = 0, i = s.size() - 1;
        while (s[i] == \u0027 \u0027)
            --i;
        while (i >= 0) {
            if (s[i] == \u0027 \u0027)
                break;
            ++len;
            --i;
        }
        return len;
    }
};