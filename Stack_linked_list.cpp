#include <iostream>
#include <cmath>
#include<bits/stdc++.h>

using namespace std;
struct Node{
    int val;
    Node *next;
};

int count_nodes(Node *top){
    int num = 0;
    while(top){
        top = top->next;
        num++;
    }
    return num;
}
void push(Node *&top,int val){
    Node *newnode = new Node;
    newnode->val = val;
    newnode->next = NULL;
    if (!top){
        top = newnode;
    }
    else{
        newnode->next = top;
        top = newnode;
    }
}

void pop(Node *&top){
    if (!top)
        cout<<"Stack is empty"<<endl;
    else{
        Node *curr = top;
        cout<<"Popped: "<<top->val<<endl;
        top = top->next;
        delete curr;
    }
}

int peak(Node *top){
    if(!top){
        cout<<"Stack is empty"<<endl;
        return -1;
    }
    return top->val;
}

void display(Node *top){
    if(!top){
        cout<<"Stack is empty"<<endl;
    }
    else{
        cout<<"Stack elements are:"<<endl;
        while(top){
            cout<<top->val<<" ";
            top = top->next;
        }
        cout<<endl;
    }
}
int main(){
    Node *s;
    push(s,1);
    push(s,2);
    push(s,3);
    push(s,4);
    display(s);
    pop(s);
    cout<<peak(s)<<endl;
    pop(s);
    display(s);
    return 0;
}
