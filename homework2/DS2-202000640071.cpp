#include<bits/stdc++.h>
using namespace std;
/*
信息与计算科学
梁致嘉
202000640071
*/
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
typedef pair<node*,int> P;

int is_leave(node* &n){return (n!=NULL)&&(n->left==NULL&&n->right==NULL);}
int is_in_node(node* &n){return (n!=NULL)&&(n->left==NULL&&n->right==NULL);}

class SearchTree
{
    private:
        node* root;
        // void BST_insert(node* &n,int ip)
        // {
        //     cout<<ip<<endl;
        //     if(n==NULL) this->root = new node(ip);
        //     else if(ip==n->val) return;
        //     else if(ip>n->val) this->BST_insert(n->right,ip);
        //     else this->BST_insert(n->left,ip);
        // }
        void print_mid(node* n)
        {
            if(n==NULL) return;
            this->print_mid(n->left);
            printf("%d ",n->val);
            this->print_mid(n->right);
        }
    public:
        void sort_print(){
            this->print_mid(this->root);
            // printf("%d",this->root->val);
        }
        
        SearchTree()
        {
            this->root = NULL;
        }
        SearchTree(int lst[],int size)
        {
            this->root = new node(lst[0]);
            for(int i=1;i<size;++i)
            {
                // cout<<lst[i]<<endl;
                this->insert(lst[i]);
            }
        }
        void insert(int ip)
        {
            node* n = new node(ip);  // 新建一个节点
            if (root == NULL) {  // 如果树为空，新节点为根节点
                root = n;
                return;
            }
            
            node* cur = root;
            while (cur != NULL) {  // 在树中查找插入位置
                // cout<<cur->val<<" ";
                if (ip < cur->val) {
                    if (cur->left == NULL) {
                        cur->left = n;
                        return;
                    }
                    cur = cur->left;
                } else {
                    if (cur->right == NULL) {
                        cur->right = n;
                        return;
                    }
                    cur = cur->right;
                }
            }
            // cout<<endl;
        }
        int get_hk_sum(int k)
        {
            queue<P> que;
            que.push(P{root,0});
            int op = 0;
            while (!que.empty())
            {
                P tmp_p = que.front(); que.pop();
                if(is_leave(tmp_p.first)&&tmp_p.second==k)
                {
                    // printf("%d ",tmp_p.first->val);
                    op+=tmp_p.first->val;
                }
                if(tmp_p.second<k)
                {
                    if(tmp_p.first->left!=NULL) que.push(P{tmp_p.first->left,tmp_p.second+1});
                    if(tmp_p.first->right!=NULL) que.push(P{tmp_p.first->right,tmp_p.second+1});
                }
            }
            // cout<<endl;
            return op;
        }

};

int main()
{
    int lst[13] = {6,12,2,7,10,16,1,4,5,11,9,3,8};
    SearchTree Tree = SearchTree(lst,13);
    int k; cin>>k;
    // Tree.sort_print();
    cout<<Tree.get_hk_sum(k);
    return 0;
}