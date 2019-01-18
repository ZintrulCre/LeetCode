// #1
class Solution {
public:
    int findPairs(vector<int> &nums, int k) {
        map<int, int> knums;
        int ret = 0;
        for (auto num: nums)
            ++knums[num];
        for (auto m:knums) {
            if (m.second > 1 && k == 0)
                ++ret;
            else if (knums[m.first - k] > 0 && k > 0)
                ++ret;
        }
        return ret;
    }
};


// #2
class Solution {
public:
    int findPairs(vector<int> &nums, int k) {
        set<vector<int>> pairs;
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = i + 1; j < nums.size(); ++j) {
                if (abs(nums[i] - nums[j]) == k) {
                    pairs.insert(vector<int>{nums[i], nums[j]});
                }
            }
        }
        return pairs.size();
    }
};
