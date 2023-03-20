#include<bits/stdc++.h>
using namespace std;

int get_feb(int idx)
{
    assert(idx>=1);
    if(idx==1||idx==2) return 1;
    return get_feb(idx-1)+get_feb(idx-2);
}

int main()
{
    for(int i=1;i<=10;++i) printf("%d ",get_feb(i));
    return 0;
}