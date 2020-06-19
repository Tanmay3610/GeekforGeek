#include<bits/stdc++.h>
using namespace std;

int countIterative(int n, int *arr){
    for(int i = 2; i < n + 1; i++)
        for(int j = 1; j <= i; j++)
            arr[i] = arr[i] + arr[i-j] * arr[j-1];
    return arr[n];
}

int countRecursive(int n, int *arr){
    if(arr[n] != 0)
        return arr[n];
    int res = 0;
    for(int i = 0; i<n; i++)
        res = res + arr[i] * arr[n-i-1];
    return res;   
}

int main(){
    int n;
    cin>>n;
    int arr[n+1];
    for(int i = 0; i<n + 1; i++)
        arr[i] = 0;
    arr[0] = 1;
    arr[1] = 1;
    cout<<"Iterative Approach: "<<countIterative(n, arr)<<endl;
    cout<<"Recursive Approach: "<<countRecursive(n, arr)<<endl;
    return 0;
}
