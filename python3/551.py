class Solution:
    def checkRecord(self, s):
        """
        :type s: str
        :rtype: bool
        """
        if s.count(\u0027A\u0027) > 1 or s.count(\u0027LLL\u0027) > 0:
            return False
        return True