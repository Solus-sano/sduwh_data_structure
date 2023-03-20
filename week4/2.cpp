#include<bits/stdc++.h>
using namespace std;

const int L_max=0x3f3f3f;

int flag[L_max+5];

void opt(char lst[],int l,int r,int idx)
{
    if(idx>r)
    {
        for(int i=l;i<=r;++i) if(flag[i]==1) printf("%c ",lst[i]);
        printf("\n");
        return;
    }
    
    flag[idx]=0;
    opt(lst,l,r,idx+1);
    flag[idx]=1;
    opt(lst,l,r,idx+1);
}

int main()
{
    char ip[3]={'a','b','c'};
    opt(ip,0,2,0);
    return 0;
}