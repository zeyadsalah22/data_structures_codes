#include <iostream>
#include <cmath>
#include<bits/stdc++.h>

using namespace std;
struct Node{
    int val;
    Node *left;
    Node *right;
};

void insert(Node *&root,int val){
    if(!root){
        Node *newnode = new Node;
        newnode->val = val;
        newnode->left = newnode->right = NULL;
        root = newnode;
    }
    else if(root->val>val)
        insert(root->left,val);
    else
        insert(root->right,val);
}

void dfs_inorder(Node *root){
    if(!root) {
        return;
    }
    dfs_inorder(root->left);
    cout<<root->val<<" ";
    dfs_inorder(root->right);
}

void dfs_preorder(Node *root){
    if(!root) {
        return;
    }
    cout<<root->val<<" ";
    dfs_preorder(root->left);
    dfs_preorder(root->right);
}

void dfs_postorder(Node *root){
    if(!root) {
        return;
    }
    dfs_postorder(root->left);
    dfs_postorder(root->right);
    cout<<root->val<<" ";

}

int tree_height(Node *root){
    if (!root)
        return 0;
    return max(tree_height(root->right), tree_height(root->left))+1;
}

void print_level(Node*root,int level){
    if(!root)
        return;
    if(level==0)
        cout<<root->val<<" ";
    print_level(root->left,level-1);
    print_level(root->right,level-1);
}

void bfs(Node *root){
    int height = tree_height(root);
    for(int i=0;i<height;i++){
        print_level(root,i);
    }
    cout<<endl;
}

Node *search(Node *root,int val){
    if (!root || root->val==val){
        return root;
    }
    else if(root->val>val)
        return search(root->left,val);
    else
        return search(root->right,val);
}

int main(){
    Node *root = NULL;
    insert(root,16);
    insert(root,8);
    insert(root,32);
    insert(root,64);
    insert(root,4);
    insert(root,30);
    dfs_inorder(root);
    cout<<endl;
    dfs_postorder(root);
    cout<<endl;
    dfs_preorder(root);
    cout<<endl;
    bfs(root);
    cout<<search(root,30)->val<<endl;
    cout<<search(root,25)->val<<endl;
    return 0;
}
