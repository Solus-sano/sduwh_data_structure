#include<bits/stdc++.h>
using namespace std;
/*
Implementation of link list,include:
    insert
    remove
    bubble sort
*/



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
    void print()
    {
        node<T>* tmp_l = this->begin;
        while(tmp_l->next!=this->end)
        {
            tmp_l = tmp_l->next;
            cout<<tmp_l->item<<" ";
        }
        printf("\n");
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

int main()
{
    Linklist<int> lst = Linklist<int>();
    lst.insert(1,0);
    lst.insert(2,0);
    lst.insert(3,0);
    lst.insert(4,0);
    lst.print();
    lst.remove(1);
    lst.print();
    lst.insert(5,0);
    lst.print();
    lst.sort();
    lst.print();
    return 0;
}