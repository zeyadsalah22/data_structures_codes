#include <iostream>
#include <cmath>
#include<bits/stdc++.h>

using namespace std;
struct Node{
    int val;
    Node *next;
};
bool isempty(Node *front,Node *rear){
    return !front && !rear;
}

void enqueue(Node *&front,Node *&rear,int val){
    Node *newnode = new Node;
    newnode->val = val;
    newnode->next = NULL;
    if(isempty(front,rear)){
        rear = newnode;
        front = rear;
    }
    else{
        rear->next = newnode;
        rear = newnode;
    }
}

void dequeue(Node *&front,Node *&rear){
    if (isempty(front,rear))
        cout<<"Underflow"<<endl;
    else{
        cout<<"Dequeued: "<<front->val<<endl;
        if(!front->next){
            delete front;
            rear = NULL;
            front = NULL;
        }
        else{
            Node *temp = front;
            front = front->next;
            delete temp;
        }
    }
}

int peak(Node *front,Node *rear){
    if(isempty(front,rear)){
        cout<<"Queue is empty"<<endl;
        return -1;
    }
    return front->val;
}

void display(Node *front, Node *rear){
    if(isempty(front,rear)){
        cout<<"Queue is empty"<<endl;
    }
    else{
        Node *curr = front;
        cout<<"Queue elements are:"<<endl;
        while(curr){
            cout<<curr->val<<" ";
            curr = curr->next;
        }
        cout<<endl;
    }
}
int main(){
    Node *f = NULL;
    Node *r = NULL;
    dequeue(f,r);
    enqueue(f,r,1);
    enqueue(f,r,2);
    enqueue(f,r,3);
    enqueue(f,r,4);
    enqueue(f,r,5);
    display(f,r);
    dequeue(f,r);
    cout<<peak(f,r)<<endl;
    dequeue(f,r);
    display(f,r);
    return 0;
}
