def max_ribbon_cut(ribbon_length, possible_cuts):

    dp = [0] * (ribbon_length + 1)

    for cut in possible_cuts:
        dp[cut] = 1
    
    for length in range(1, ribbon_length+1):
        for cut in possible_cuts:
            if cut <= length:
                if dp[length-cut]:
                    var1 = dp[length - cut] + 1
                    dp[length] = max(dp[length], var1)
    return dp

print(max_ribbon_cut(5, [2,3,5]))
print(max_ribbon_cut(7, [2,3]))
print(max_ribbon_cut(13, [3,5,7]))
print(max_ribbon_cut(7, [3,5]))
