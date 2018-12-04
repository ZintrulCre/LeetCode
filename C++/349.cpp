class Solution {
public:
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2) {
        vector<int> inter;
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        auto iter1 = unique(nums1.begin(), nums1.end());
        auto iter2 = unique(nums2.begin(), nums2.end());
        nums1.erase(iter1,nums1.end());
        nums2.erase(iter2,nums2.end());
        int i = 0, j = 0;
        while (i < nums1.size() && j < nums2.size()) {
            if (nums1[i] == nums2[j]) {
                inter.push_back(nums1[i]);
                ++i;
                ++j;
            } else if (nums1[i] < nums2[j])
                ++i;
            else
                ++j;
        }
        return inter;
    }
};
