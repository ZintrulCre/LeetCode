class Solution {
public:
    int lenLongestFibSubseq(vector<int> &A) {
        auto size = A.size();
        if (size < 3)
            return 0;
        int maxLen = 0;
        unordered_map<int, int> S;
        for (int i = 0; i < size; ++i)
            S.insert(pair<int, int>(A[i], i));
        vector<int> seq(size, 0);
        seq[0] = seq[1] = 1;
        for (int i = 0; i < size; ++i) {
            for (int j = 2; j < size; ++j) {
                if (S.find(A[j] - A[i]) != S.end()) {
                    seq[j] = seq[j] == 0 ? 3 : max(seq[j], seq[S[A[j] - A[i]]] + 1);
                    maxLen = max(maxLen, seq[j]);
                }
            }
        }
        return maxLen;
    }
};
