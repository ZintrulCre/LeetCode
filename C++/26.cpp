// #1
class Solution {
public:
    int removeDuplicates(vector<int> &nums) {
        auto size = nums.size();
        if (!size)
            return 0;
        int i = 0, j = 1;
        while (j < size) {
            if (nums[j] != nums[i])
                nums[++i] = nums[j];
            ++j;
        }
        return i + 1;
    }
};


// #2
class Solution {
public:
    int removeDuplicates(vector<int> &nums) {
        int i = 0, j = 0;
        while (j < nums.size()) {
            while (nums[j] == nums[j + 1] && j + 1 < nums.size())
                ++j;
            nums[i++] = nums[j++];
        }
        return i;
    }
};
