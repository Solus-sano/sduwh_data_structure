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
int sum;
int is_leave(node* &n){return (n!=NULL)&&(n->left==NULL&&n->right==NULL);}

void get_sum(node* root,queue<int> que)
{
    if(root==NULL) return;
    que.push(root->val);
    if(is_leave(root))
    {
        int tmp_sum = 0;
        while(!que.empty())
        {
            tmp_sum = tmp_sum*10+que.front();
            que.pop();
        }
        sum+=tmp_sum;
    }
    else
    {
        get_sum(root->left,que);
        get_sum(root->right,que);
    }
}

int main()
{
    node* root = new node(6);
    root->left = new node(1);
    root->right = new node(5);
    root->left->left = new node(3);
    root->left->right = new node(7);
    queue<int> que;
    get_sum(root,que);
    printf("%d",sum);
    return 0;
}