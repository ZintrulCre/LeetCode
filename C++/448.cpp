class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int> &nums) {
        auto size = nums.size();
        vector<int> appeared(size, 0), ret;
        for (auto n :nums)
            appeared[n - 1] = 1;
        for (int i = 0; i < size; ++i)
            if (appeared[i] == 0)
                ret.push_back(i + 1);
        return ret;
    }
};