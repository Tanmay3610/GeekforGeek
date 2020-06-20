//Question Link : https://www.geeksforgeeks.org/remove-duplicates-from-an-unsorted-linked-list/

/*
Concept of double pointer is being used in this approach.
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

void remove_duplicate(){
    node* first = head;
    node* second = NULL; 
    while(first != NULL && first->next != NULL){
        second = first;
        while(second->next != NULL){
            if(second->next->data == first->data)
                second->next = second->next->next;
            else
                second = second->next;
        }
        first = first->next;
    }
}

int main(){
    int arr[] = {2,2,2,2};
    int size = sizeof(arr)/sizeof(arr[0]);
    for(int i = 0; i<size; i++)
        createNode(arr[i]);
    showList();
    remove_duplicate();
    showList();
    return 0;
}
