//Question Link : https://www.geeksforgeeks.org/subset-sum-problem-dp-25/

//Subset Sum Problem

/*
  Using Dynamic Programming
*/

#include<bits/stdc++.h>
using namespace std;

bool isSubsetSum(int *set, int n, int sum){
    bool dp[n][sum + 1];
    for(int i = 0; i<n; i++){
        dp[i][0] = true;
    }
    for(int j = 1; j <= sum; j++){
        dp[0][j] = j == set[0];
    }
    
    for(int i = 1; i<n; i++)
        for(int j = 1; j <= sum; j++){
            if(set[i] > j)
                dp[i][j] = dp[i-1][j];
            else
                dp[i][j] = dp[i-1][j] || dp[i - 1][j - set[i]];
        }
    return dp[n-1][sum];
}

int main(){
    int set[] = { 1,5,11,5 }; 
    int sum = 4; 
    int n = sizeof(set) / sizeof(set[0]); 
    if (isSubsetSum(set, n, sum)) 
        printf("Found a subset with given sum"); 
    else
        printf("No subset with given sum"); 
    return 0;
}
