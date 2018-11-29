// #1
class Solution {
public:
    vector<int> sortArrayByParity(vector<int> &A) {
        int size = A.size();
        if (size == 0) return A;
        int even_sub = 0;
        for (int i = 0; i < size; ++i) {
            if (A[i] % 2 == 0) {
                swap(A[i], A[even_sub]);
                ++even_sub;
            }
        }
        return A;
    }
};


// #2
class Solution {
public:
    vector<int> sortArrayByParity(vector<int> &A) {
        vector<int> even, odd;
        for (int a : A) {
            if (a % 2 == 0)
                even.push_back(a);
            else
                odd.push_back(a);
        }
        even.insert(even.end(), odd.begin(), odd.end());
        return even;
    }
};