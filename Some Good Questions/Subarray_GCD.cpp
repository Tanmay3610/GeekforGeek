//Question Link : https://www.codechef.com/problems/SUBGCD

/*

* This is very simple question, all you have to do is to find the GCD of the given array.
  But why? So, Check out its editorial on this link : http://discuss.codechef.com/problems/SUBGCD

*/

#include<bits/stdc++.h>
using namespace std;


int gcd(int a, int b) 
{ 
    if (a == 0) 
        return b; 
    return gcd(b % a, a); 
} 
  
int findGCD(int arr[], int n) 
{ 
    int result = arr[0]; 
    for (int i = 1; i < n; i++) 
    { 
        result = gcd(arr[i], result); 
  
        if(result == 1) 
        { 
           return 1; 
        } 
    } 
    return result; 
} 

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int arr[n];
        for(int i = 0; i<n; i++)
            cin>>arr[i];
        findGCD(arr, n) == 1 ?cout<<n<<endl : cout<<-1<<endl;
    }
    return 0;
}
