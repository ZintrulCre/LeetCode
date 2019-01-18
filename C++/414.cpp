class Solution {
public:
    int thirdMax(vector<int> &nums) {
        int size = nums.size();
        if (size < 3)
            return *max_element(nums.begin(), nums.end());
        int *first = nullptr, *second = nullptr, *third = nullptr;
        for (int i = 0; i < size; ++i) {
            if (!first) {
                first = new int;
                *first = nums[i];
            } else if (*first < nums[i]) {
                if (second) {
                    if (!third)
                        third = new int;
                    *third = *second;
                } else
                    second = new int;
                *second = *first;
                *first = nums[i];
            } else if (*first == nums[i])
                continue;
            else if (!second) {
                second = new int;
                *second = nums[i];
            } else if (*second < nums[i]) {
                if (!third)
                    third = new int;
                *third = *second;
                *second = nums[i];
            } else if (*second == nums[i])
                continue;
            else {
                if (!third) {
                    third = new int;
                    *third = nums[i];
                } else if (*third < nums[i])
                    *third = nums[i];
            }
        }
        return third ? *third : *first;
    }
};
