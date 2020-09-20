def canPartition(nums):
        
        total_sum = sum(nums)
        
        if total_sum % 2 == 1:
            return False
        
        subset_sum = total_sum//2
        
        dp = []
        n = len(nums)
        
        for i in range(n+1):
            dp.append([0]*(subset_sum+1))
            
        for i in range(1, n+1):
            for j in range(1, subset_sum+1):
                val1 = 0
                if nums[i-1]<=j:
                    val1 = dp[i-1][j-nums[i-1]] + nums[i-1]
                dp[i][j] = max(val1, dp[i-1][j])
                if dp[i][j] == subset_sum:
                    return True
        
        return False

print(canPartition([1,2,5]))
print(canPartition([1, 2, 3, 4]))
print(canPartition([1, 1, 3, 4, 7]))
print(canPartition([2, 3, 4, 6]))
