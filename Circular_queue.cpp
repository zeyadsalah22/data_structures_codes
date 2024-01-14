#include <iostream>
#include <cmath>
#include<bits/stdc++.h>

using namespace std;
const int qsize = 4;
struct Queue{
    int arr[qsize];
    int front = 0, rear = 0, counter = 0;
};

bool isfull(Queue q){
    return q.rear==q.front && q.counter==qsize;
}

bool isempty(Queue q){
    return q.rear==q.front && q.counter==0;
}

void enqueue(Queue &q,int val){
    if (isfull(q))
        cout<<"Queue is full"<<endl;
    else{
        q.arr[q.rear] = val;
        q.rear = (q.rear+1)%qsize;
        q.counter++;
    }
}

void dequeue(Queue &q){
    if (isempty(q))
        cout<<"Underflow"<<endl;
    else{
        cout<<"Dequeued: "<<q.arr[q.front]<<endl;
        q.front = (q.front+1)%qsize;
        q.counter--;
    }
}

int peak(Queue q){
    if(isempty(q)){
        cout<<"Queue is empty"<<endl;
        return -1;
    }
    return q.arr[q.front];
}

void display(Queue q){
    if(isempty(q)){
        cout<<"Queue is empty"<<endl;
    }
    else{
        cout<<"Queue elements are:"<<endl;
        for(int i=0;i<q.counter;i++)
            cout<<q.arr[(i+q.front)%qsize]<<" ";
        cout<<endl;
    }
}
int main(){
    Queue q;
    dequeue(q);
    enqueue(q,1);
    enqueue(q,2);
    enqueue(q,3);
    enqueue(q,4);
    enqueue(q,5);
    display(q);
    dequeue(q);
    cout<<peak(q)<<endl;
    enqueue(q,5);
    display(q);
    return 0;
}
