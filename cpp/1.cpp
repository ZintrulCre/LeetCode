class Solution {
public:
	std::vector<int> twoSum(std::vector<int>& nums, int target) {
		std::map<int, int> hash;
		int size = nums.size();
		std::vector<int> ret;
		for (int i = 0; i < size; ++i) {
			if (hash.find(target - nums[i]) != hash.end()) {
				ret.push_back(hash[target - nums[i]]);
				ret.push_back(i);
				return ret;
			}
			hash.insert(std::pair<int, int>(nums[i], i));
		}
	}
};