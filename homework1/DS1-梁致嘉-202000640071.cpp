#include<bits/stdc++.h>
using namespace std;
/*
信息与计算科学
梁致嘉
202000640071
*/
struct Friend
{
    string name;
    int scr;

    bool operator>(Friend& n1)
    {
        return this->scr>n1.scr;
    }
};

template<typename T>
class ArrayList{
    protected:
    T* node;
    int length,size;
    public:
        ArrayList()
        {
            this->node = new T[16];
            this->length=16;
            this->size=0;
        }
        ArrayList(T lst[],int len)
        {
            this->node = new T[len+16];
            for(int i=0;i<len;++i) this->node[i] = lst[i];
            // this->merge_sort(0,len-1);
            this->length=len+16;
            this->size=len;
        }
        int get_size(){return this->size;}

        void re_malloc()
        {
            T* tmp_node = this->node;
            this->node = new T[this->length+16];
            for(int i=0;i<this->size;++i) this->node[i]=tmp_node[i];
            delete[] tmp_node;
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

        void merge_sort(int l,int r)
        {
            assert((l>=0&&l<this->size)&&(r>=0&&r<this->size));
            if(l>=r) return;
            int mid = (l+r)/2;//printf("%d %d\n",l,r);
            this->merge_sort(l,mid); this->merge_sort(mid+1,r);
        
            int i=l,j=mid+1,k=0;
            T* tmp_lst = new T[r-l+10];
            // printf("%d %d %d %d %d\n",i,j,l,r,mid);
            while((i<=mid)&&(j<=r)) tmp_lst[k++] =(this->node[i]>this->node[j]) ? this->node[j++] : this->node[i++];
            // cout<<"tmp: "; this->print();
            while(i<=mid) tmp_lst[k++] = this->node[i++];
            while(j<=r) tmp_lst[k++] = this->node[j++];
            // for(int x=0;x<k;++x)
            // {
            //     cout<<tmp_lst[x];
            // }
            // cout<<k<<endl;
            while(k) this->node[--j] = tmp_lst[--k];
            // this->print();
            delete[] tmp_lst;
        }
        // ~ArrayList();
};


class FriendList:public ArrayList<Friend>{
    string name;
    public:
        void set_name(string ip){this->name = ip;}
        string get_name(){return this->name;}

        void add_frend(string str,int scr)
        {
            for(int i=0;i<this->size;++i)
            {
                if(this->node[i].name==str)
                {
                    this->node[i].scr = scr;
                    return;
                }
            }
            Friend new_frend = {str,scr};
            this->insert(this->size,new_frend);
        }

        void print()
        {
            cout<<this->name<<":  ";
            for(int i=0;i<this->size;++i)
            {
                cout<<"{"<<this->node[i].name<<","<<this->node[i].scr<<"} ";
            }
            printf("\n");
        }
};

class FriendShip{
    FriendList* lst;
    int size,length;

    public:
        FriendShip()
        {
            this->lst = new FriendList[16];
            this->length = 16; this->size = 0;
        }

        void re_malloc()
        {
            FriendList* tmp_lst = this->lst;
            this->lst = new FriendList[this->length+16];
            for(int i=0;i<this->size;++i) this->lst[i]=tmp_lst[i];
            delete[] tmp_lst;
        }

        int bin_search(string name)
        {
            if(this->size == 0) return 0;
            if(this->lst[this->size-1].get_name()<name) return this->size;
            int l = 0,r = this->size-1,mid;
            while(l<r)
            {
                mid = (l+r)/2;
                if(this->lst[mid].get_name()>=name) r = mid;
                else l = mid+1;
            }
            return r;
        }

        void insert(int idx,FriendList x)
        {
            assert(idx>=0&&idx<=this->size);
            if(this->size+8>this->length) this->re_malloc();

            for(int i=this->size;i>idx;--i) this->lst[i]=this->lst[i-1];
            this->lst[idx]=x;
            this->size++;
        }

        void add_frend_ship(string n1,string n2,int scr)
        {
            int idx = this->bin_search(n1);
            if(this->lst[idx].get_name()!=n1)
            {
                FriendList tmp_frend_lst = FriendList();
                tmp_frend_lst.set_name(n1);
                this->insert(idx,tmp_frend_lst);
            }
            this->lst[idx].add_frend(n2,scr);
        }

        void print()
        {
            printf("===============================\n");
            for(int i=0;i<this->size;++i) this->lst[i].print();
            printf("===============================\n");
        }

        void print_frend_lst(string name)
        {
            int idx = this->bin_search(name);
            FriendList tar_lst = this->lst[idx]; 
            assert(tar_lst.get_name()==name);
            int l = tar_lst.get_size();
            tar_lst.merge_sort(0,l-1);
            printf("===============================\n");
            tar_lst.print();
            printf("===============================\n");
        }
};

int main()
{
    string idx2name[] = {"zhao","qian","sun","li","zhou","wu","zheng","wang"};
    int data[8][8]={
        {0,1,2,3,4,5,0,0},
        {2,0,6,1,1,0,0,0},
        {0,2,0,1,0,1,3,5},
        {6,1,3,0,0,0,1,5},
        {0,5,3,3,0,2,2,0},
        {1,5,2,0,3,0,0,6},
        {5,0,0,1,1,2,0,1},
        {3,0,0,2,5,3,3,0}
    };
    
    FriendShip F_ship = FriendShip();
    for(int i=0;i<8;++i)
    {
        for(int j=0;j<8;++j)
        {
            if(data[i][j]) F_ship.add_frend_ship(idx2name[i],idx2name[j],data[i][j]);
        }
    }
    printf("initial: \n");
    F_ship.print();

    F_ship.add_frend_ship("zhao","zhou",1);F_ship.add_frend_ship("zhao","zheng",3);
    F_ship.add_frend_ship("sun","li",5);
    F_ship.add_frend_ship("wu","sun",5);F_ship.add_frend_ship("wu","wang",1);
    F_ship.add_frend_ship("zheng","li",3);F_ship.add_frend_ship("zheng","wu",6);
    F_ship.add_frend_ship("wang","wu",1);
    printf("change: \n");
    F_ship.print();
    string ip;
    printf("input someone's name to search his friendship: \n");
    cin>>ip;
    cout<<ip<<"'s friendship: \n";
    F_ship.print_frend_lst(ip);
    return 0;
}