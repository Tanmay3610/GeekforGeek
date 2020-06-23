//Question Link : https://www.geeksforgeeks.org/binomial-coefficient-dp-9/

/*

    Concept Used : C(n,r) = C(n - 1, r - 1) + C(n - 1, r)

*/

#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007

int dp[1001][1001];

int C(int n, int r){
    if(r > n - r)
        r = n - r;
    if(n < 0 || r < 0)
        return 0;
    if(dp[n][r] != 0)
        return dp[n][r];
    dp[n][n - r] = dp[n][r] = (C(n - 1, r - 1)%mod + C(n - 1, r)%mod)%mod;
    return dp[n][r];
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,r;
        memset(dp, 0, sizeof(dp));
        cin>>n>>r;
        for(int i = 0; i<n+1; i++){
            dp[i][0] = 1;
            dp[i][i] = 1;
        }   
    cout<<C(n,r)<<endl;    
    }
    return 0;
}
