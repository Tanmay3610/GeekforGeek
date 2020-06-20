//Question Link : https://www.geeksforgeeks.org/subset-sum-problem-dp-25/

//Subset Sum Problem

/*
  Solved without dynamic programming
*/

#include<bits/stdc++.h>
using namespace std;

bool isSubsetSum(int *set, int n, int sum){
    if(sum == 0)
        return true;

    if(sum >0 && n <= 0)
        return false;
    
    if(sum < 0)
        return false;

    return isSubsetSum(set, n - 1, sum) || isSubsetSum(set, n - 1, sum - set[n - 1]);
}

int main(){
    int set[] = { 3, 34, 4, 12, 5, 2 }; 
    int sum = 30; 
    int n = sizeof(set) / sizeof(set[0]); 
    if (isSubsetSum(set, n, sum)) 
        printf("Found a subset with given sum"); 
    else
        printf("No subset with given sum"); 
    return 0;
}
