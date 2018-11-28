class NumArray {
public:
    NumArray(vector<int> nums) {
        int size = nums.size();
        sum = vector<int>(size + 1, 0);
        for (int i = 0; i < size; ++i)
            sum[i + 1] = sum[i] + nums[i];
    }

    int sumRange(int i, int j) {
        return sum[j + 1] - sum[i];
    }

private:
    vector<int> sum;
};
