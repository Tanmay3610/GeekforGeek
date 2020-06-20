//Question Link : https://www.geeksforgeeks.org/find-length-of-loop-in-linked-list/

/*
We know that Floyd’s Cycle detection algorithm 
terminates when fast and slow pointers meet at a 
common point. We also know that this common point 
is one of the loop nodes. We store the address of this common point in a pointer variable say ptr. 
Then we initialize a counter with 1 and start from the common point and 
keeps on visiting next node and increasing the counter till we again 
reach the common point(ptr). At that point, the value of the counter will be equal to the length of the loop.
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

int finding_cycle_length(){
    node* fast = head;
    node* slow = head;
    node* ptr = NULL;
    while(fast != NULL){
        fast = fast->next;
        if(fast == NULL){
            cout<<"No Loop";
            return 0;
        }            
        fast = fast->next;
        if(fast == NULL){
            cout<<"No Loop";
            return 0;
        }            
        slow = slow->next;
        if(slow == fast){
            ptr = fast; // or ptr = slow;
            int count = 1;
            itr = ptr;
            while(itr->next != ptr){
                itr = itr->next;
                count = count + 1;
            }
            return count;
        }
    }
}

int main(){
    int arr[] = {1,2};
    int size = sizeof(arr)/sizeof(arr[0]);
    for(int i = 0; i<size; i++)
        createNode(arr[i]);
    showList();
    cout<<finding_cycle_length();
    return 0;
}
