#include<stdio.h>
#include<iostream>
#include<cmath>

using namespace std;

int maxProfitRecursion(int arr[], int s, int e, int year) {
    if(s==e)
        return year*arr[s];
    
    int p1 = arr[s]*year + maxProfitRecursion(arr, s+1, e, year+1);
    int p2 = arr[e]*year + maxProfitRecursion(arr, s, e-1, year+1);

    return max(p1, p2);
}

int maxProfitDp(int arr[], int year) {
    int dp[100][100]={-1};

    // Step 1 - Set Base DP, max value possible for each bottle at last year
    for(int i=0; i<year; i++) {
        dp[i][i] = year*arr[i];
    }

    for(int y=year-1; y>=1; y--) {
        for(int i=0; i<y; i++) {
            int j = year - y + i;
            int ans1 = dp[i][j-1] + arr[j] * y;
            int ans2 = dp[i+1][j] + arr[i] * y;
            dp[i][j] = max(ans1, ans2);
        }
    }

    for(int i=0;i<year;i++) {
        for(int j=0;j<year;j++)  {
            cout<<dp[i][j] << " ";
        }
        cout<<endl;
    }

    return dp[0][year-1];

}

int main() {
    cout<<"Enter number of years and wine problem:"<<endl;
    int n;
    cin>>n;

    
    //Input 
    int arr[n];
    for(int i=0;i<n;i++) {
        cout<<"\nEnter val of wine - "<<i+1<<endl;
        int val;
        cin>>val;
        arr[i]=val;
    }

    // Recursion
    int result_1 = maxProfitRecursion(arr, 0, n-1, 1);
    cout<<"\nRecursion output: "<<result_1<<endl;

    int result_2 = maxProfitDp(arr, n);
    cout<<"\nDP output: "<<result_2<<endl;

    // Bottom Up - DP
}