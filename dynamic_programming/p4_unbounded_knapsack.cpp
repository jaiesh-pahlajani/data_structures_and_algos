#include<iostream>
#include<stdio.h>
#include<stdio.h>

using namespace std;

int unboundedKnapsack(int wt[], int val[], int n, int w) {
    /*
        Knapsack problem where the same item can be repeated multiple times
    */

   int dp[100][100]={0};

   for(int i=1; i<=n; i++) {
       for(int j=1;j<=w;j++) {
           if(wt[i-1]<=j) {
               cout<<val[i-1] + dp[i][j-wt[i-1]]<<endl;
               dp[i][j] = max(dp[i][j], val[i-1] + dp[i][j-wt[i-1]]);
           }
           dp[i][j] = max(dp[i-1][j], dp[i][j]);
       }
   }

   for(int i=0; i<=n; i++) {
       for(int j=0;j<=w;j++) {
           cout<<dp[i][j]<<" ";
       }
       cout<<endl;
   }

   return dp[n][w];
}

int main() {

    cout<<"Enter total weight"<<endl;
    int w;
    cin>>w;

    cout<<"\nEnter number of items"<<endl;
    int n;
    cin>>n;

    int wt[n];
    int val[n];
    for(int i=0; i<n; i++) {
        cout<<"\nEnter val of item - "<<i<<endl;
        cin>>val[i];

        cout<<"\nEnter wt of item - "<<i<<endl;
        cin>>wt[i];
    }

    int result = unboundedKnapsack(wt, val, n, w);

    cout<<"\nAnswer: "<<result;

    return 0;
}
