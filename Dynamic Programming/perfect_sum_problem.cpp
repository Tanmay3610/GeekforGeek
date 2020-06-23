//Question link : https://www.geeksforgeeks.org/perfect-sum-problem-print-subsets-given-sum/

/*

* This is not a dynamic solution but still a nice approach to print subsets. To understand it 
in a better way, do dry run.

*/


#include<bits/stdc++.h>
using namespace std;

void display(vector<int> v) 
{ 
    for (int i = 0; i < v.size(); ++i) 
        printf("%d ", v[i]); 
    printf("\n"); 
}

void solve(int *arr, int n, int sum, vector<int> p){
    if(sum == 0){
        display(p);
        return;
    }

    if(sum < 0 || n <= 0)
        return;
        
    vector<int> b = p; 
    solve(arr, n - 1, sum, b);
    b.push_back(arr[n-1]); 
    solve(arr, n - 1, sum - arr[n - 1], b);
        
}   

int main(){
    int arr[] = {1,2,3,4};
    int size = sizeof(arr)/sizeof(arr[0]);
    int sum = 4;
    vector<int> p; 
    solve(arr, size, sum, p);    
}
