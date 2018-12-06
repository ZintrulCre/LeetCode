class Solution {
public:
    int distributeCandies(vector<int> &candies) {
        unordered_set<int> kind;
        int half = candies.size() / 2;
        for (auto candy : candies) {
            if (kind.find(candy) == kind.end()) {
                kind.insert(candy);
                --half;
            }
            if (half <= 0)
                break;
        }
        return kind.size();
    }
};
