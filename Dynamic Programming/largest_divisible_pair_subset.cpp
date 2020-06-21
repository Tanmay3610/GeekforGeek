//Question Link : https://www.geeksforgeeks.org/largest-divisible-pairs-subset/

/*

* This is a very nice Question using dynamic programming.

*/

#include<bits/stdc++.h>
using namespace std;

void solve(vector <int> arr){
    int dp[arr.size()];
    memset(dp, 0, sizeof(dp));
    int count = 1; 
    for(int j = 0; j<arr.size() - 1; j++){
        if(dp[j] != 0){
            continue;
        }
        count = 0;
        int tmp = j;
        for(int i = j; i<arr.size(); i++){
            if(arr[i] % arr[tmp] == 0){
                count++;
                dp[i] = max(count, dp[i]); //It may be possibele that dp[i] already has larger value
                tmp = i;
            }
        }
    }
    int maximum = INT_MIN;
    for(int i = 0; i< arr.size(); i++)
        maximum = max(maximum, dp[i]);
    cout<<maximum<<endl;       
}

int main()
{
    vector <int> arr;
    int n;
    cin>>n;
    for(int i = 0; i<n; i++){
        int a;
        cin>>a;
        arr.push_back(a);
    }    
    sort(arr.begin(), arr.end());
    solve(arr);
}
