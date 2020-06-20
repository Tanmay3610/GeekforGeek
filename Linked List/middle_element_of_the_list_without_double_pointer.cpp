#include<bits/stdc++.h>
using namespace std;

typedef struct Node{
    int data;
    struct Node* next;
}node;

node* head = NULL;
node* itr = NULL;

void createNode(int data){
    node* newNode = (node*)malloc(sizeof(node));
    newNode->data = data;
    newNode->next = NULL;
    if(head == NULL)
        head = newNode;
    else{
        itr = head;
        while(itr->next != NULL){
            itr = itr->next;
        }
        itr->next = newNode;
    }
}

void showList(){
    itr = head;
    while(itr != NULL){
        cout<<itr->data<<" ";
        itr = itr->next;
    }
    cout<<endl;
}

node* findMiddleList(){
    node* ptr = head;
    itr = head;
    int count = 0;
    while(itr != NULL){
        if(count % 2 != 0)
            ptr = ptr->next;
        count = count + 1;
        itr = itr->next;
    }
    return ptr;
}

int main(){
    int arr[] = {1,2};
    int size = sizeof(arr)/sizeof(arr[0]);
    for(int i = 0; i<size; i++)
        createNode(arr[i]);
    showList();
    findMiddleList() == NULL ? cout<<"No element exist" : cout<<findMiddleList()->data;
    return 0;
}
