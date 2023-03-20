#include<bits/stdc++.h>
using namespace std;
/*
Implementation of array list,include:
    insert
    remove
*/



template<typename T>
class ArrayList{
    T* node;
    int length,size;
    public:
        ArrayList()
        {
            this->node = new T[16];
            this->length=16;
            this->size=0;
        }

        void re_malloc()
        {
            T* tmp_node = new T[this->length+16];
            for(int i=1;i<this->size;++i) tmp_node[i]=this->node[i];
            this->node=tmp_node;
        }

        void push_back(T ip)
        {
            if(this->size+8>this->length) this->re_malloc();
            this->node[this->size]=ip;
            size++;
        }

        void remove(int idx)
        {
            assert(idx>=0&&idx<this->size);
            for(int i=idx+1;i<this->size;++i) this->node[i-1]=this->node[i];
            this->size--;
        }

        void insert(int idx,T x)
        {
            assert(idx>=0&&idx<=this->size);
            if(this->size+8>this->length) this->re_malloc();

            for(int i=this->size;i>idx;--i) this->node[i]=this->node[i-1];
            this->node[idx]=x;
            this->size++;
        }

        void print()
        {
            for(int i=0;i<this->size;++i) cout<<this->node[i]<<" ";
            printf("\n");
        }
};

int main()
{
    ArrayList<int> lst = ArrayList<int>();
    for(int i=1;i<=3;++i) lst.push_back(i);
    lst.print();
    lst.insert(1,200);
    lst.print();
    lst.remove(2);
    lst.print();

    return 0;

}
