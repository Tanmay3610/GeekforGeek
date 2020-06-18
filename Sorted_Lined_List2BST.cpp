//Solved by Tanmay Agarwal
#include<bits/stdc++.h>
using namespace std;

typedef struct Node{
    int data;
    struct Node* next;
}node;

typedef struct Tree{
    struct Tree* right;
    struct Tree* left;
    int key;
}tree;

node* head = NULL;
node* itr = NULL;

void addNode(int data){
    node* newNode = (node*)malloc(sizeof(node));
    newNode->data = data;
    newNode->next = NULL;
    if(head == NULL)
        head = newNode;
    else{
        itr = head;
        while(itr->next != NULL)
            itr = itr->next;
        itr->next = newNode;
    }
}

tree* convert2BST(int init ,int last, node* start, int size){
    cout<<init<<" "<<last<<" "<<size<<" ";
    if(init > last)
        return NULL;
    if(init >= size || last < 0)
        return NULL;
    itr = start;
    int mid = (init + last)/2;
    cout<<mid<<endl;
    int count = init;
    if(itr == head){
        count = 0;
        while(count != init){
            itr = itr->next;
            count = count + 1;
        }
    }
    count = init;
    while(count != mid){
        itr = itr->next;
        count++;
    }
    tree* newNode = (tree*)malloc(sizeof(tree));
    newNode->key = itr->data;
    newNode->right = convert2BST2(mid + 1, last, itr->next, size);
    newNode->left = convert2BST2(init, mid - 1, head, size);
    return newNode;
}

void showTree(tree* root){
    if(root == NULL)
        return;
    showTree(root->left);
    cout<<root->key<<" ";
    showTree(root->right);
}

void showLinkedList(){
    itr = head;
    while(itr != NULL){
        cout<<itr->data<<" ";
        itr = itr->next;
    }
    cout<<endl;
}

int main(){
    int arr[] = {1,2,3,4,5,6};
    int size = sizeof(arr)/sizeof(arr[0]);
    for(int i = 0; i < size; i++)
        addNode(arr[i]);    
    tree* root = NULL;
    root = convert2BST(0, size - 1, head, size);
    showTree(root);
    return 0;
}
