#include <iostream>
using namespace std;
struct Node{
    int val;
    Node *next;
};

int count_nodes(Node *head){
    int counter = 0;
    while(head){
        counter++;
        head = head->next;
    }
    return counter;
}
void insert_start(Node *&head,int val){
    Node *newnode = new Node;
    newnode->val = val;
    newnode->next = NULL;
    if (head==NULL)
        head = newnode;
    else{
        newnode->next = head;
        head = newnode;
    }
}

void insert_end(Node *&head,int val){
    Node *newnode = new Node;
    newnode->val = val;
    newnode->next = NULL;
    if (head==NULL)
        head = newnode;
    else{
        Node *curr = head;
        while(curr->next){
            curr = curr->next;
        }
        curr->next = newnode;
    }
}

void insert_pos(Node *&head,int val,int pos){
    if (pos<1 || pos> count_nodes(head))
        cout<<"Invalid position"<<endl;
    else{

        Node *curr = head;
        for (int i = 1;i<pos;i++){
            curr = curr->next;
        }
        Node *newnode = new Node;
        newnode->val = val;
        newnode->next = curr->next;
        curr->next = newnode;
    }
}

void display(Node *head){
    while(head){
        cout<<head->val<<' ';
        head = head->next;
    }
    cout<<endl;
}

int sum_list(Node *head){
    int sum = 0;
    while(head){
        sum+=head->val;
        head = head->next;
    }
    return sum;
}
void delete_start(Node *&head){
    if(head==NULL)
        cout<<"List is empty"<<endl;
    else{
        Node *curr = head;
        head = head->next;
        delete curr;
    }
}

void delete_end(Node *&head){
    if(head==NULL)
        cout<<"List is empty"<<endl;
    else{
        Node *curr = head;
        if (head->next==NULL){
            head = head->next;
            delete curr;
        }
        else{
            Node *before_curr = head;
            curr = head->next;
            while(curr->next){
                curr = curr->next;
            }
            delete curr;
            before_curr->next = NULL;
        }
    }
}

void delete_pos(Node *&head,int pos){
    if(head==NULL)
        cout<<"List is empty";
    else{
        if (pos<1 || pos>count_nodes(head))
            cout<<"Invalid position";
        else{
            Node *before_curr;
            Node *curr = head;
            for(int i=1;i<pos;i++){
                before_curr = curr;
                curr = curr->next;
            }
            before_curr->next = curr->next;
            delete curr;
        }
    }
}

void delete_linked_list(Node *&head){
    Node *temp;
    while(head){
        temp = head;
        head = head->next;
        delete temp;
    }
    cout<<"List deleted succesfully"<<endl;
}

void reverse_list(Node *&head){
    Node *curr = head;
    Node *prev = NULL,*next;
    while(curr){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
}

int main(){
    Node *head = NULL;
    insert_start(head,2);
    insert_end(head,4);
    insert_start(head,1);
    insert_pos(head,3,2);
    display(head);
    cout<<sum_list(head)<<endl;
    insert_pos(head,5,6);
    reverse_list(head);
    display(head);
    reverse_list(head);
    delete_start(head);
    display(head);
    delete_pos(head,2);
    display(head);
    delete_end(head);
    display(head);
    delete_linked_list(head);
    display(head);
    return 0;
}
