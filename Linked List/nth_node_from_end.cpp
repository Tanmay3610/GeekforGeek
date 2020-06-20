//Question Link: https://www.geeksforgeeks.org/nth-node-from-the-end-of-a-linked-list/

/*This question can be done easily by finding the length of the linked list, but let's do it by anotgehr way around using two pointer concept.
Complexity of this is O(n)*/

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

node* nth_from_last(int n){
    node* main_ptr = head;
    node* ref_ptr = head;

    int count = 0;
    
    while(count < n){
        if(ref_ptr == NULL){
            cout<<"This dosent exist";
            return NULL;
        }
        ref_ptr = ref_ptr->next;
        count++;
    }

    while(ref_ptr != NULL){
        ref_ptr = ref_ptr->next;
        main_ptr = main_ptr->next;
    }

    return main_ptr;
}

int main(){
    int arr[] = {1,2,3,4,5};
    int size = sizeof(arr)/sizeof(arr[0]);
    for(int i = 0; i<size; i++)
        createNode(arr[i]);
    cout<<(nth_from_last(3)->data)<<endl;
    showList();
    return 0;
}
