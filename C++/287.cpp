// #1
class Solution {
public:
    int findDuplicate(vector<int> &nums) {
        auto size = nums.size();
        if (size == 0)
            return 0;
        int fast = nums[0], slow = nums[0];
        do {
            fast = nums[nums[fast]];
            slow = nums[slow];
        } while (fast != slow);
        fast = nums[0];
        while (fast != slow) {
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};


// #2
class Solution {
public:
    int findDuplicate(vector<int> &nums) {
        for (int i = 0; i < nums.size(); ++i) {
            int &cur = nums[abs(nums[i]) - 1];
            if (cur < 0)
                return abs(nums[i]);
            cur = -cur;
        }
        return 0;
    }
};
