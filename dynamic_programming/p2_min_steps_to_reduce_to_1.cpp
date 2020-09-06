#include<stdio.h>
#include<iostream>
#include<cmath>

using namespace std;

int min_steps(int n) {
    /*
        Function to calculate the number of steps to reduce a number n

        Operations that can be performed are -
        1. Divide by 3
        2. Divide by 2 
        3. Subtract 1
    */

   int arr[n+1];
   arr[0]=0;
   arr[1]=1;
   arr[2]=1;
   arr[3]=1;

    for(int i=4;i<=n;i++) {
        arr[i] = arr[i-1] + 1;
        int q1;
        int q2;
        if(i%3==0) {
            arr[i] = min(arr[i], arr[i/3]+1);
        }
        if(i%2==0) {
            arr[i] = min(arr[i], arr[i/2]+1);
        }
    }

    return arr[n];
}

int main() {
    int n;
    cout<<"Enter the number:"<<endl;
    cin>>n;
    int result = min_steps(n);

    cout<<"\nAnswer: "<<result<<endl;

    return 0;
}