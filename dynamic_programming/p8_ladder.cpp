using namespace std;

#include <iostream>
#include <vector>

int CountWays(int n) {
    /*
    Given a stair with ‘n’ steps, 
    implement a method to count how many possible ways 
    are there to reach the top of the staircase, given that,
    at every step you can either take 1 step, 2 steps, or 3 steps.
    */
    vector<int> dp(n + 1);
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;

    for (int i = 3; i <= n; i++) {
      dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
    }

    return dp[n];
  }

int main(int argc, char *argv[]) {
  cout << CountWays(3) << endl;
  cout << CountWays(4) << endl;
  cout << CountWays(5) << endl;
}