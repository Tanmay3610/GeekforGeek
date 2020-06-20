//Question Link : https://www.geeksforgeeks.org/remove-duplicates-from-a-sorted-linked-list/

/*
Double pointer approach has been used. Though single pointer approach is pretty much same as this one.
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

vector <int> stack_array;

void remove_duplicate(){
    node* first = head;
    node* second = head->next;
    while(second != NULL){
        if(first->data == second->data){
            first->next = second->next;    
            second = second->next;        
        }
        first = first->next;
        second = second->next;
    }    
}

int main(){
    int arr[] = {1,1,2,3};
    int size = sizeof(arr)/sizeof(arr[0]);
    for(int i = 0; i<size; i++)
        createNode(arr[i]);
    showList();
    remove_duplicate();
    showList();
    return 0;
}
