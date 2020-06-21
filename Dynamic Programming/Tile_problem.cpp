#include<bits/stdc++.h>
using namespace std;

//Question Link : https://www.geeksforgeeks.org/tiling-problem/

/*

* Sometimes questions seems to be hard but in actual tghey ain't. Try to do it once again without seeing solution.

*/

int dp[1000];

int count(int n){
    if(dp[n] != -1)
        return dp[n];
    dp[n] = count(n - 2) + count(n - 1);
    return dp[n];
}

int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        memset(dp, -1, sizeof(dp));
        cin>>n;
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 2;
        cout<<count(n)<<endl;
    }
    
    
}
