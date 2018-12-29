class Solution:
    def rotate(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: void Do not return anything, modify nums in-place instead.
        """
        nums.reverse()
        nums[:k] = nums[k-1::-1]
        nums[k:len(nums)] = nums[len(nums) - 1:k - 1:-1]
        