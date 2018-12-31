# 1
class Solution:
    def findDisappearedNumbers(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        return list(set(range(1, len(nums) + 1)) - set(nums))

        
# 2
class Solution:
    def findDisappearedNumbers(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        appeared = [0] * len(nums)
        for n in nums:
            appeared[n - 1] = 1
        ret = []
        for i in range(0,len(appeared)):
            if appeared[i] == 0:
                ret.append(i + 1)
        return ret