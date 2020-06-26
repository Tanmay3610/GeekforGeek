//Question link : https://www.geeksforgeeks.org/find-maximum-length-snake-sequence/

/*

* This approach is recursive approach

*/

#include<bits/stdc++.h>
using namespace std;

#define M 4 
#define N 4 

vector <pair<int, int> > stackArr;


int findSnakeSequence(int mat[][N], int currx, int curry, bool visited[][N]){
    stackArr.push_back(make_pair(currx, curry));
    if(currx == N - 1 && curry == M - 1){
        return 0;
    }        
    if(((currx + 1 < N && (visited[currx + 1][curry] == false && mat[currx + 1][curry] - 1 == mat[currx][curry]) || (currx + 1 < N && visited[currx][curry + 1] == false) && mat[currx + 1][curry] + 1 == mat[currx][curry])) && ((curry + 1 < M && mat[currx][curry + 1] - 1 == mat[currx][curry]) || (curry + 1 < M && mat[currx][curry + 1] + 1 == mat[currx][curry]))){
        return max(1 + findSnakeSequence(mat, currx + 1, curry, visited), 1 + findSnakeSequence(mat, currx, curry + 1, visited));
    }      
    else if(currx + 1 < N && visited[currx + 1][curry] == false && mat[currx + 1][curry] + 1 == mat[currx][curry] || currx + 1 < N && mat[currx + 1][curry] - 1 == mat[currx][curry]){
        return 1 + findSnakeSequence(mat, currx + 1, curry, visited);
    }        
    else if(curry + 1 < M && visited[currx][curry + 1] == false && mat[currx][curry + 1] + 1 == mat[currx][curry] || curry + 1 < M && mat[currx][curry + 1] - 1 == mat[currx][curry]){
        return 1 + findSnakeSequence(mat, currx, curry + 1, visited);
    }        
    else{
        stackArr.pop_back();
        return 0;
    } 
}



int main() 
{ 
    int mat[M][N] = 
    { 
        {9, 6, 5, 2}, 
        {8, 7, 6, 5}, 
        {7, 3, 1, 6}, 
        {1, 1, 1, 7}, 
    }; 
    
    bool visited[M][N];
    memset(visited, false, sizeof(visited));
    findSnakeSequence(mat, 0, 0, visited); 
    for(int i = 0; i < stackArr.size(); i++)
        cout<<'('<<stackArr[i].first<<','<<stackArr[i].second<<')'<<" ";
    return 0; 
}
