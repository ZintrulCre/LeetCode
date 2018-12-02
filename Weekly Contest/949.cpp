class Solution {
public:
    string largestTimeFromDigits(vector<int> &A) {
        for (int i = 0; i < A.size(); ++i)
            ++digit[A[i]];
        Find(0);
        if (time.size() < 5)
            return "";
        return time;
    }

    void Find(int m) {
        if (m == 5) {
            find = true;
            return;
        } else if (m == 0) {
            for (int i = 2; i >= 0; --i) {
                if (insert(i)) {
                    Find(m + 1);
                    if (find)
                        return;
                    time = time.substr(0, time.size() - 1);
                    ++digit[i];
                }
            }
        } else if (m == 1) {
            if (time[0] == '2') {
                for (int i = 3; i >= 0; --i) {
                    if (insert(i)) {
                        Find(m + 1);
                        if (find)
                            return;
                        time = time.substr(0, time.size() - 1);
                        ++digit[i];
                    }
                }
            } else {
                for (int i = 9; i >= 0; --i) {
                    if (insert(i)) {
                        Find(m + 1);
                        if (find)
                            return;
                        time = time.substr(0, time.size() - 1);
                        ++digit[i];
                    }
                }
            }
        } else if (m == 2) {
            time += ":";
            Find(m + 1);
            if (find)
                return;
            time = time.substr(0, time.size() - 1);
        } else if (m == 3) {
            for (int i = 5; i >= 0; --i) {
                if (insert(i)) {
                    Find(m + 1);
                    if (find)
                        return;
                    time = time.substr(0, time.size() - 1);
                    ++digit[i];
                }
            }
        } else if (m == 4) {
            for (int i = 9; i >= 0; --i) {
                if (insert(i)) {
                    Find(m + 1);
                    if (find)
                        return;
                    time = time.substr(0, time.size() - 1);
                    ++digit[i];
                }
            }
        }
    }

    bool insert(int i) {
        if (digit.find(i) != digit.end()) {
            time += to_string(i);
            Remove(i);
            return true;
        }
        return false;
    }

    void Remove(int k) {
        --digit[k];
        if (digit[k] == 0)
            digit.erase(k);
    }

private:
    unordered_map<int, int> digit;
    string time;
    bool find = false;
};
