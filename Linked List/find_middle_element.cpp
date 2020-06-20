//Question Link : https://www.geeksforgeeks.org/write-a-c-function-to-print-the-middle-of-the-linked-list/

/* 
This question is can easliy done by using naive methods, but in this
approach I have used the concept of double pointers, in which one pointer 
is running at a speed of 2x and  other is running at a speed of x.
*/

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
    node* ref_ptr = head;
    node* main_ptr = head;

    while(ref_ptr != NULL){
        ref_ptr = ref_ptr->next;
        if(ref_ptr == NULL)
            return main_ptr;
        ref_ptr = ref_ptr->next;
        if(ref_ptr == NULL)
            return main_ptr;
        main_ptr = main_ptr ->next;    
    }
    return NULL;
}

int main(){
    int arr[] = {1};
    int size = sizeof(arr)/sizeof(arr[0]);
    for(int i = 0; i<size; i++)
        createNode(arr[i]);
    showList();
    findMiddleList() == NULL ? cout<<"No element exist" : cout<<findMiddleList()->data;
    return 0;
}
