//Question Link : https://www.geeksforgeeks.org/gold-mine-problem/

/*

* In this question, I didn't if n is not equal to m, bcoz I have messed up with n and m. 
* But approach of this question is very unique and very new. 

*/

/*

* Approach : Firstly, I create another 2D matrix solve which is similar to given matrix with additional walls of 0 
* all around it. Then I started to take three values in a row from the last second column of solve matrix and saving the 
* maximum of all the values in the previous column + its own value.

*/

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    n = m = 3;
    int gold[n][m] =     {{1, 3, 3},
                          {2, 1, 4},
                          {0, 6, 4}};
    
    int solve[n+2][m+2];
    for(int i = 0; i<=m; i++){
        solve[0][i] = 0;
        solve[n + 1][i] = 0;
    }
    
    for(int i = 0; i <= n; i++){
        solve[i][0] = 0;
        solve[i][n + 1] = 0;
    }

    for(int i = 1; i<=n; i++)
        for(int j = 1; j<=m; j++)
            solve[i][j] = gold[i-1][j-1];
            

    for(int i = 0; i<=n + 1; i++){
        for(int j = 0; j<=m + 1; j++)
            cout<<solve[i][j]<<" ";
        cout<<endl;
    }

    for(int i = m-1; i > 0 ;i--){
        for(int j = 1; j<=n; j++){
            int maximum = max(solve[j][i + 1], max(solve[j + 1][i + 1], solve[j - 1][i + 1]));
            solve[j][i] = maximum + solve[j][i];
        }         
    }

    int maximum = INT_MIN;
    for(int i = 1; i <= n; i++)
        maximum = max(maximum, solve[i][1]);
    
    cout<<maximum;


    
}
