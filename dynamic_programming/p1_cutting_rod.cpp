#include<iostream>
#include<stdio.h>
#include <cmath>

using namespace std;

int maxProfitForRod(int rod_val[], int tot_rod_length, int n) {
    /*
        Function to calculate the max profit of a rod
    */
    int dp[100] = {0};

    for(int i=1; i<=tot_rod_length; i++) {
        for(int k=1; k<=i; k++) {
            if(k>n)
                continue;
            dp[i] = max(dp[i], rod_val[k] + dp[i-k]);
        }
    }

    return dp[tot_rod_length];
}

int main() {
    
    cout<<"Enter array size:";
    int n;
    cin>>n;

    int rod_val[n+1];

    rod_val[0] = 0;
    
    // Value for each rod size
    for(int i = 1; i<=n;  i++) {
        int val;
        cout<<"\nEnter value for rod of length - "<<i<<endl;
        cin>>val;
        rod_val[i] = val;
    }

    int tot_rod_length;
    cout<<"\nEnter the total rod length for which you want to know the max profit that can be acheived by cutting the rod:";
    cin>>tot_rod_length;
    
    int max_profit = maxProfitForRod(rod_val, tot_rod_length, n);
    cout<<"\n"<<max_profit<<endl;

    return 0;
}