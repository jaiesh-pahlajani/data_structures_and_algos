#include<iostream>
#include<stdio.h>
#include<cmath>

using namespace std;

int main() {
    cout<<"Enter N:"<<endl;
    int n;
    cin>>n;

    int arr[n][n];

    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {

            cout<<"\nEnter value for i="<<i<<" j="<<j<<endl;
            cin>>arr[i][j];
        }
    }

    int dp[n][n];

    dp[0][0]=arr[0][0];

    // Set base row
    for(int i=1; i<n; i++) {
        dp[0][i] = dp[0][i-1] + arr[0][i];
    }

    // Set base column
    for(int i=1; i<n; i++) {
        dp[i][0] = dp[i-1][0] + arr[i][0];
    }

    
    
    /* 
        Can only moves downwards or sidewards
    */
    for(int i=1;i<n;i++) {
        for(int j=1;j<n;j++) {
            int val1 = dp[i-1][j] + arr[i][j];
            int val2 = dp[i][j-1] + arr[i][j];

            dp[i][j] = min(val1, val2);
        }
    }

    // Print matrix
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }

    // Print final distance
    cout<<"\nAnswer:"<<dp[n-1][n-1]<<endl;
}