class Solution {
public:
    int search(vector<int> &nums, int target) {
        int i = 0, j = nums.size() - 1;
        if (j < 0)
            return -1;
        while (i < j) {
            int mid = i + (j - i) / 2;
            if (nums[mid] > nums[i] && nums[mid] > nums[j])
                i = mid + 1;
            else if (nums[mid] < nums[i] && nums[mid] < nums[j])
                j = mid;
            else
                break;
        }
        i = nums[i] > nums[j] ? j : i;
        int start = 0, end = i - 1;
        if (target < nums[0] || i == 0) {
            start = i;
            end = nums.size() - 1;
        }
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (nums[mid] == target)
                return mid;
            else if (nums[mid] > target)
                end = mid - 1;
            else
                start = mid + 1;
        }
        return -1;

    }
};