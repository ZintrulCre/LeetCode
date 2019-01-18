#1
class Solution:
    def lengthOfLIS(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        size = len(nums)
        seq = [nums[0]] if size > 0 else []
        for i in range(1, size):
            x, y = 0, len(seq)
            while(x < y):
                mid = x + (y-x) // 2
                if nums[i] > seq[mid]:
                    x = mid + 1
                else:
                    y = mid
            if y == len(seq):
                seq.append(nums[i])
            else:
                seq[y] = nums[i]
        return len(seq)


#2
class Solution:
    def lengthOfLIS(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        size, LIS = len(nums), 1 if len(nums) > 0 else 0
        dp = [1 for i in range(size)]
        for i in range(1, size):
            for j in range(0, i):
                if nums[j] < nums[i]:
                    dp[i] = max(dp[i], dp[j] + 1)
            LIS = max(LIS, dp[i])
        return LIS
