// #1
class Solution {
public:
    void rotate(vector<int> &nums, int k) {
        auto size = nums.size();
        k %= size;
        RotateVector(nums, 0, size);
        RotateVector(nums, 0, k);
        RotateVector(nums, k, size);
    }

    void RotateVector(vector<int> &nums, int i, int j) {
        while (i < j) {
            swap(nums[i], nums[j]);
            ++i;
            --j;
        }
    }
};


// #2
class Solution {
public:
    void rotate(vector<int> &nums, int k) {
        k %= nums.size();
        while (k > 0) {
            int &temp = nums.back();
            nums.pop_back();
            nums.insert(nums.begin(), temp);
            --k;
        }
    }
};
