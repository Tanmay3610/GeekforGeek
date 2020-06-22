//Question Link : https://practice.geeksforgeeks.org/problems/stickler-theif/0#:~:text=Stickler%20the%20thief%20wants%20to,maximize%20the%20amount%20he%20loots.


/*

* I have applied both approaches, dynamic and recursive.
* The one which is in comments is recursive approach and other one is dynamic.
* The question gives TLE when going though recursive approach so i have implemented dynamic approach 
* during solving this problem.

*/

// **************** RECURSIVE APPROACH ********************//
/*
#include<bits/stdc++.h>
using namespace std;

int staticSum = 0;
int solve(int *arr, int n, int sum){
    if(staticSum < sum)
        staticSum = sum;
    if(n <= 0)
        return 0;
    solve(arr, n - 2, sum + arr[n - 1]);
    solve(arr, n - 1, sum);        
}

int main(){
    int t;
    cin>>t;
    while(t--){
        staticSum = 0;
        int n;
        cin>>n;
        int arr[n];
        for(int i = 0; i<n; i++)
            cin>>arr[i];
        solve(arr, n, 0);
        cout<<staticSum<<endl;    
    }
        
    return 0;
}
*/

// **************** DYNAMIC APPROACH ********************//

#include<bits/stdc++.h>
using namespace std;

int staticSum = 0;
int solve(int *arr, int n, int sum, int *dp){
    dp[0] = arr[0];
    dp[1] = max(arr[0], arr[1]);
    for(int i = 2; i<n; i++){
        dp[i] = max(dp[i-1], dp[i-2] + arr[i]);
    }
    return dp[n - 1];
}

int main(){
    int t;
    cin>>t;
    while(t--){
        staticSum = 0;
        int n;
        cin>>n;
        int arr[n];
        for(int i = 0; i<n; i++)
            cin>>arr[i];
        int dp[n]; 
        cout<<solve(arr, n, 0, dp)<<endl;
    }
        
    return 0;
}
