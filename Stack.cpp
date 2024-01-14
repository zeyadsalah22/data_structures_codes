#include <iostream>
#include <cmath>
#include<bits/stdc++.h>

using namespace std;
const int sizee = 100;
struct Stack{
    int arr[sizee];
    int top = -1;
};

bool isfull(Stack s){
    return s.top==sizee-1;
}

bool isempty(Stack s){
    return s.top==-1;
}

void push(Stack &s,int val){
    if (isfull(s))
        cout<<"Overflow"<<endl;
    else
        s.arr[++s.top] = val;
}

void pop(Stack &s){
    if (isempty(s))
        cout<<"Underflow"<<endl;
    else
        cout<<"Popped: "<<s.arr[s.top--]<<endl;
}

int peak(Stack s){
    if(isempty(s)){
        cout<<"Stack is empty"<<endl;
        return -1;
    }
    return s.arr[s.top];
}

void display(Stack s){
    if(isempty(s)){
        cout<<"Stack is empty"<<endl;
    }
    else{
        cout<<"Stack elements are:"<<endl;
        for(int i=s.top;i>=0;i--)
            cout<<s.arr[i]<<" ";
        cout<<endl;
    }
}
int main(){
    Stack s;
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
