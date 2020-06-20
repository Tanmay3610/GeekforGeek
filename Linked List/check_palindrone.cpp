//Question Link : https://www.geeksforgeeks.org/function-to-check-if-a-singly-linked-list-is-palindrome/

/*
In this we made use of stack
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

void check_palindrone(){
    itr = head;
    int flag = 0;
    while(itr != NULL){
        stack_array.push_back(itr->data);
        itr = itr->next;
    }

    itr = head;
    while(itr != NULL){
        int temp = stack_array.back();
        stack_array.pop_back();
        if(itr->data != temp)
            flag = 1;
        itr = itr->next;
    }

    if(flag == 0)
        cout<<"Palindrone";
    else
        cout<<"Not a Palindrone";
}

int main(){
    int arr[] = {1,2,1};
    int size = sizeof(arr)/sizeof(arr[0]);
    for(int i = 0; i<size; i++)
        createNode(arr[i]);
    showList();
    check_palindrone();
    return 0;
}
