//Question Link : https://www.geeksforgeeks.org/coin-change-dp-7/

/*
  Using Dynamic Approach
*/

#include<bits/stdc++.h>
using namespace std;

int solve(int *arr, int m, int n){
    int dp[m][n+1];
    for(int i = 0; i<m; i++)
        dp[i][0] = 1;

    for(int i = 1; i<= n; i++){
        if(i % arr[0] == 0)
            dp[0][i] = 1;
        else
            dp[0][i] = 0;
    }
    
    for(int i = 1; i < m; i++){
        for(int j = 1; j <= n; j++){
            if(arr[i] > j)
                dp[i][j] = dp[i-1][j];
            else
                dp[i][j] = dp[i-1][j] + dp[i][j - arr[i]];
        }
    }
    return dp[m-1][n];
}

int main(){
    int arr[] = {1, 2, 3}; 
    int m = sizeof(arr)/sizeof(arr[0]);
    int n = 5;
    cout<<solve(arr, m, n);
    return 0;
}
