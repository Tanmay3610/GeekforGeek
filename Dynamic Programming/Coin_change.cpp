// Question Link : https://www.geeksforgeeks.org/coin-change-dp-7/

#include<bits/stdc++.h>
using namespace std;

int solve(int *arr, int m, int n){
    // If sum manages to get 0 in the given coins
    if(n == 0)
        return 1;
    
    // If sum goes below 0
    if(n < 0)
        return 0;
    
    // If sum is not 0 but we are outta coins
    if(m <= 0 && n > 0)
        return 0;
    return solve(arr, m, n - arr[m-1]) + solve(arr, m-1, n);
}

int main(){
    int arr[] = {1, 2, 3}; 
    int m = sizeof(arr)/sizeof(arr[0]);
    int n = 4;
    cout<<solve(arr, m, n);
    return 0;
}
