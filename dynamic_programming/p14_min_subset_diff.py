def min_subset_diff(nums):

    dp = []

    n = len(nums)

    total_sum = sum(nums)

    capacity = total_sum//2

    for i in range(n+1):
        dp.append([0]*(capacity+1))

    for i in range(1, n+1):
        for j in range(1, capacity+1):
            val1 = 0
            if nums[i-1]<=j:
                val1 = dp[i-1][j-nums[i-1]] + nums[i-1]
            dp[i][j] = max(dp[i-1][j], val1)
    
    return (total_sum - dp[n][capacity]) - dp[n][capacity]

print(min_subset_diff([1, 2, 3, 9]))
print('------------------------------------')
print(min_subset_diff([1, 2, 7, 1, 5]))
print('------------------------------------')
print(min_subset_diff([1, 3, 100, 4]))
