#include<stdio.h>
#include<iostream>

using namespace std;

int main() {
    int n;
    cout<<"Enter number n"<<endl;
    cin>>n;

    int arr[n+1];
    arr[0]=0;
    arr[1]=1;
    for(int i=2; i<=n; i++) {
        arr[i] = arr[i-1] + arr[i-2];
    }

    for(int i=0; i<=n; i++) {
        cout<<arr[i]<<" ";
    }

    cout<<"\nAnswer:"<<arr[n]<<endl;

    return 0;
}