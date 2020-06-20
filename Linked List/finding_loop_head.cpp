//Question Link : Self-designed

/*
  Ques: To find the head of loop in linked list.
  Approach: 
  * Find the length of the loop
  * Maintain two pointers and make a difference of (length - 1) between them
  * Now start procedding both the pointers by one step 
  * If second->next == first then first will be the loop head.
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

void findHead(int length){
    node* second = head;
    node* first = head;
    
    /* Maintaining difference of (length - 1) between two pointers */
    while(length != 0){
        second = second->next;
        length = length - 1;
    }
    
    /* Retreving loop head by checking second->next == first condition */
    while(true){
        if(second->next == first){
          cout<<first->data;
          return;
        }
        second = second->next;
        first = first->next;
        
        if(first == second){
            cout<<first->data;
            return;            
        }
    }
}

void loopHead(){
    node* slow = head;
    node* fast = head;
    node* tmp = NULL;
    
  
    /* Checking if the loop is present or not */
    while(fast != NULL){
        fast = fast->next;
        if(fast->next == NULL){
            cout<<"No Loop";
            return;
        }
        fast = fast->next;
        
        slow = slow->next;
        if(slow == fast){
            tmp = slow;
            break;
        }        
    }
  
    /* Finding Length of the loop */
    itr = tmp;
    int length = 1;
    while(itr->next != tmp){
        itr = itr->next;
        length++;
    }
    
    /*finding loop head*/
    findHead(length - 1);
}

int main(){
    int arr[] = {1,2,3,4};
    int size = sizeof(arr)/sizeof(arr[0]);
    for(int i = 0; i<size; i++)
        createNode(arr[i]);
    head->next->next->next->next = head; 
    loopHead();
    
    return 0;
}
