#include <iostream>
#include <cmath>
#include<bits/stdc++.h>

using namespace std;
struct Node{
    char val;
    int priority;
    Node *next;
};

void enqueue(Node *&head,char val,int priority){
    Node *newnode = new Node;
    newnode->val = val;
    newnode->priority = priority;
    newnode->next = NULL;
    if(!head){
        head = newnode;
    }
    else{
        if(head->priority<priority){
            newnode->next = head;
            head = newnode;
        }
        else{
            Node *curr= head;
            while(curr->next && curr->next->priority>priority)
                curr = curr->next;
            newnode->next = curr->next;
            curr->next = newnode;
        }
    }
}

void dequeue(Node *&head){
    if (!head)
        cout<<"Underflow"<<endl;
    else{
        cout<<"Dequeued: "<<head->val<<endl;
        Node *temp = head;
        head = head->next;
        delete temp;
    }
}

char peak(Node *head){
    if(!head){
        cout<<"Queue is empty"<<endl;
        return -1;
    }
    return head->val;
}

void display(Node *head){
    if(!head){
        cout<<"Queue is empty"<<endl;
    }
    else{
        Node *curr = head;
        cout<<"Queue elements are:"<<endl;
        while(curr){
            cout<<curr->val<<" Priority: "<<curr->priority<<endl;
            curr = curr->next;
        }
    }
}
int main(){
    Node *pq = NULL;
    dequeue(pq);
    enqueue(pq,'b',6);
    enqueue(pq,'a',9);
    enqueue(pq,'f',3);
    enqueue(pq,'w',1);
    enqueue(pq,'i',2);
    display(pq);
    dequeue(pq);
    cout<<peak(pq)<<endl;
    dequeue(pq);
    display(pq);
    return 0;
}
