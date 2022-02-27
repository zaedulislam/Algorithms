class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        
        globalMaximum: int = nums[0]
        localMaximum: int = nums[0] 
            
        for num in nums[1:]:
            localMaximum = max(num, localMaximum + num)
            globalMaximum = max(globalMaximum, localMaximum)
            
        return globalMaximum
