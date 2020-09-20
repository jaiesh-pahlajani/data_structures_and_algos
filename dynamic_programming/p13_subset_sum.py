def subset_sum_exists(nums, sum_value):
    
    n = len(nums)
    dp = []
    for i in range(n+1):
        dp.append([0]*(sum_value+1))
    
    for i in range(1, n+1):
        for j in range(1, sum_value+1):
            val1 = 0
            if(nums[i-1]<=j):
                val1 = dp[i-1][j - nums[i-1]] + nums[i-1]
            dp[i][j] = max(val1, dp[i-1][j])
            if dp[i][j] == sum_value:
                return True
    
    return False

print(subset_sum_exists([1, 2, 3, 7], 6))
print(subset_sum_exists([1, 3, 4, 8], 6))
print(subset_sum_exists([1, 2, 7, 1, 5], 10))
