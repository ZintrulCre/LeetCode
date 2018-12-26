// #1
class Solution {
public:
    int numTrees(int n) {
        vector<int> t(n + 1, 0);
        t[0] = 1;
        t[1] = 1;
        for (int i = 2; i <= n; ++i)
            for (int j = 1; j <= i; ++j)
                t[i] += t[j - 1] * t[i - j];
        return t[n];
    }
};


// #2
class Solution {
public:
    unordered_map<int, int> m;

    int numTrees(int n) {
        if (m.find(n) != m.end())
            return m[n];
        if (n == 0 || n == 1)
            return 1;
        int total = 0;
        for (int i = 1; i <= n; ++i) {
            int left = numTrees(i - 1);
            int right = numTrees(n - i);
            total += left * right;
        }
        m[n] = total;
        return total;
    }
};
