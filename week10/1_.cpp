#include<bits/stdc++.h>
using namespace std;

struct node
{
    int val;
    node* left;
    node* right;
    node(int ip)
    {
        this->val = ip;
        this->left = this->right = NULL;
    }
};

int is_leave(node* &n){return (n!=NULL)&&(n->left==NULL&&n->right==NULL);}

int get_left_sum(node* root)
{
    if(root==NULL) return 0;
    if(is_leave(root->left)) return root->left->val+get_left_sum(root->right);
    else
    {
        return get_left_sum(root->left)+get_left_sum(root->right);
    }
}

int main()
{
    node* root = new node(6);
    root->left = new node(1);
    root->right = new node(5);
    root->left->left = new node(3);
    root->left->right = new node(7);
    printf("%d",get_left_sum(root));
    return 0;
}