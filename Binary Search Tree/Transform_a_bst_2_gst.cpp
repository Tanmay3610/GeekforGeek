//By: Tanmay Agarwal
//Question link: https://www.geeksforgeeks.org/transform-bst-sum-tree/
#include<bits/stdc++.h>
using namespace std;

typedef struct Tree{
    int key;
    struct Tree* right;
    struct Tree* left;
}tree;

int sum = 0;
tree* createNode(int data){
    tree* newNode = (tree*)malloc(sizeof(tree));
    newNode->right = NULL;
    newNode->left = NULL;
    newNode->key = data;
    return newNode;
}

tree* createBST(tree* root, int data){
    if(root == NULL)
        return createNode(data);
    if(data > root->key){
        root->right = createBST(root->right, data);
    }
    if(data < root->key){
        root->left = createBST(root->left, data);
    }
    return root;
}

void showTree(tree* root){
    if(root == NULL)
        return;
    showTree(root->left);
    cout<<root->key<<" ";
    showTree(root->right);
}

void convert2gst(tree* root){
    if(root == NULL)
        return;
    convert2gst(root->right);
    sum = sum + root->key;
    root->key = sum - root->key;    
    convert2gst(root->left);    
}

int main(){
    int arr[] = {11,2,29,1,7,15,40,35};
    int size = sizeof(arr)/sizeof(arr[0]);
    tree* root = NULL;
    for(int i = 0; i < size; i++)
        root = createBST(root, arr[i]);
    showTree(root);
    convert2gst(root);
    cout<<endl;
    showTree(root);
    return 0;
}
