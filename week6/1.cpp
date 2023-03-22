#include<bits/stdc++.h>
using namespace std;

template<typename T>
struct node
{
    T item;
    node<T>* next;
};

template<typename T>
class Linklist{
    node<T>* begin;
    node<T>* end;
    int size;
public:
    int length(){return this->size;}

    Linklist()
    {
        this->begin = new node<T>;
        this->end = new node<T>;
        this->begin->next=this->end;
        this->size = 0;
    }
    Linklist(T lst[],int l,bool flag = false)
    {
        this->begin = new node<T>;
        this->end = new node<T>;
        this->size = 0;
        this->begin->next=this->end;
        if(flag) for(int i=0;i<l;++i) {this->insert(lst[i],0);}
        else for(int i=0;i<l;++i) {this->insert(lst[i],this->length());}
    }

    void print(int re = false)
    {
        node<T>* tmp_l = this->begin;
        if(re)
        {
            stack<T> cont;
            while(tmp_l->next!=this->end)
            {
                tmp_l = tmp_l->next;
                cont.push(tmp_l->item);
            }
            while(!cont.empty())
            {
                cout<<cont.top()<<" "; cont.pop();
            }
        }
        else
        {
            queue<T> cont;
            while(tmp_l->next!=this->end)
            {
                tmp_l = tmp_l->next;
                cont.push(tmp_l->item);
            }
            while(!cont.empty())
            {
                cout<<cont.front()<<" "; cont.pop();
            }
        }
        printf("\n");
    }

    T get_item(int idx)
    {
        assert(0<=idx && idx<this->size);
        node<T>* tmp = this->begin->next;
        while(idx--) tmp = tmp->next;
        return tmp->item;
    }

    void insert(T item,int idx)
    {
        assert(0<=idx && idx<=this->size);
        node<T>* add_node = new node<T>; add_node->item = item;
        node<T>* tmp_l = this->begin;
        for(int i=0;i<idx;++i) tmp_l = tmp_l->next;
        add_node->next = tmp_l->next; tmp_l->next = add_node;
        this->size++;
    }

    void remove(int idx)
    {
        assert(0<=idx && idx<this->size);
        node<T>* tmp_l = this->begin;
        for(int i=0;i<idx;++i) tmp_l = tmp_l->next;
        node<T>* rem_node = tmp_l->next;
        tmp_l->next = rem_node->next;
        delete rem_node;
        this->size--;
    }

    void sort()
    {
        for(int i=1;i<this->size;++i)
        {
            node<T>* tmp_l = this->begin->next; node<T>* tmp_r = tmp_l->next;
            int j = this->size-i;
            while (j--)
            {
                if(tmp_l->item>tmp_r->item) swap(tmp_l->item,tmp_r->item);
                tmp_l = tmp_l->next; tmp_r = tmp_r->next;
            }
        }
    }

};

Linklist<int> add(Linklist<int> a,Linklist<int> b)
{
    Linklist<int> op = Linklist<int>();
    int pre = 0;
    while(a.length()||b.length())
    {
        // printf("%d\n",op.length());
        int tmp;
        if(!a.length())
        {
            tmp = b.get_item(0)+pre;
            b.remove(0);
        }
        else if (!b.length())
        {
            tmp = a.get_item(0)+pre;
            a.remove(0);
        }
        else
        {
            tmp = a.get_item(0)+b.get_item(0)+pre;
            a.remove(0); b.remove(0);
        }
        // printf("%d %d    ",tmp,pre);
        pre = tmp/10; tmp%=10;
        // printf("%d %d\n",tmp,pre);
        op.insert(tmp,op.length());
    }
    if(pre) op.insert(pre,op.length());
    return op;
}

int main()
{
    int a[] = {9,8,9,7,5,6},b[] = {2,3,5,7,9};
    Linklist<int> a_lst = Linklist<int>(a,6,1),b_lst = Linklist<int>(b,5,1);
    a_lst.print(1); b_lst.print(1);
    Linklist<int> op_lst = add(a_lst,b_lst);
    op_lst.print(1);
    return 0;
}