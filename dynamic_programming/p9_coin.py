def all_possible_coin_change_combos(denoms, value):

    n = len(denoms)
    # init dp

    dp = []
    for i in range(n):
        dp.append([0]*(value+1))

    # init 1 column of each row as 1
    for row in dp:
        row[0]=1

    for i in range(n):
        for j in range(1, value+1):
            # exclude the coin
            if i == 0:
                exclude = 0
            else:
                exclude = dp[i-1][j]
            
            # include the coin
            if j >= denoms[i]:
                include = dp[i][j-denoms[i]]
            else: 
                include = 0

            # add both values
            dp[i][j] = include + exclude
    
    return dp

if __name__ == "__main__":
    print(all_possible_coin_change_combos([2,3,5,10], 15))
    print(all_possible_coin_change_combos([1,2,3], 5))
