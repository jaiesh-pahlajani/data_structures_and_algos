import math

def min_coin_change(amount, denoms):
    dp = [math.inf] * (amount + 1)

    for denom in denoms:
        dp[denom] = 1
    
    for value in range(1, amount+1):
        for denom in denoms:
            if denom <= value:
                var1 = dp[value - denom] + 1
                if var1 is not math.inf:
                    dp[value] = min(dp[value], var1)
    return dp

print(min_coin_change(5, [1,2,3]))
print(min_coin_change(11, [1,2,3]))
print(min_coin_change(7, [1,2,3]))
print(min_coin_change(7, [3, 5]))
