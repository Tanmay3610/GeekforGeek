//Question Link: https://www.geeksforgeeks.org/detect-loop-in-a-linked-list/

/*
This question is done by double pointer
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

void finding_cycle(){
    node* fast = head;
    node* slow = head;
    while(fast != NULL){
        fast = fast->next;
        if(fast == NULL){
            cout<<"No Loop";
            return;
        }            
        fast = fast->next;
        if(fast == NULL){
            cout<<"No Loop";
            return;
        }            
        slow = slow->next;
        if(slow == fast){
            cout<<"Loop Detected";
            return;
        }
    }
}

int main(){
    int arr[] = {1,2};
    int size = sizeof(arr)/sizeof(arr[0]);
    for(int i = 0; i<size; i++)
        createNode(arr[i]);
    showList();
    finding_cycle();
    return 0;
}
