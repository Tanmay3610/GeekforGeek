//Question Link : https://www.geeksforgeeks.org/majority-element/

/*
  First approach was dynamic approach, but space complexity of this approach is O(n) and time complexity is O(n).
  Then, we get to know another approach i.e Moore's Voting Algorithm which is better because space complexity of 
  this approach is O(1) and time complexity is O(n).
  
  
  Working of Moore's Voting Algorithm:
  The algorithm for the first phase that works in O(n) is known as Moore’s Voting Algorithm. 
  Basic idea of the algorithm is that if each occurrence of an element e can be cancelled with 
  all the other elements that are different from e then e will exist till end if it is a majority element.
*/

// *********** DYNAMIC APPROACH **************
/*
#include<bits/stdc++.h>
using namespace std;
#define MAX 1000

int dp[MAX];

int solve(int *arr, int n){
    for(int i = 0; i<n; i++){
        dp[arr[i]] = dp[arr[i]] + 1;
    }
    int maximum = 0;
    int key = 0;
    for(int i = 0; i < MAX; i++){
        if(maximum < dp[i]){
            maximum = dp[i];
            key = i;
        }
    }
    if(maximum > n/2)
        return key;
    else
        return -1;
}

int main(){
    int arr[] = {3, 1, 3, 3, 2};
    int size = sizeof(arr)/sizeof(arr[0]);
    memset(dp, 0, sizeof(dp));
    int res = solve(arr, size);
    if(res != -1)
        cout<<res<<endl;
    else
    {
        cout<<"NO"<<endl;
    }
    
    return 0;
}
*/


// ******************** MOORE'S VOTING ALGORITHM ******************************
#include<bits/stdc++.h>
using namespace std;

int solve(int *arr, int n){
    int majIndex = 0, count = 1;
    for(int i = 1; i<n; i++){
        if(arr[majIndex] == arr[i]){
            count++;
        }
        else
        {
            count--;
        }
        if(count == 0){
            majIndex = i;
            count = 1;
        }        
    }
    int majCount = 0;
    for(int i = 0; i<n; i++){
        if(arr[i] == arr[majIndex])
            majCount++;
    }
    if(majCount > n/2)
        return arr[majCount];
    else
        return -1;
}

int main(){
    int a[] = {1, 3, 3, 3, 2}; 
    int size = (sizeof(a))/sizeof(a[0]);
    cout<<solve(a, size)<<endl;    
}
