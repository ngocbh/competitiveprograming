#include <bits/stdc++.h>

using namespace std;
ifstream fi("chords.inp");
ofstream fo("chords.out");
const long maxn=1000000+100;
int n,c[2*maxn]={0},d[2*maxn]={0},e[2*maxn]={0},a,b,ix=0,res=0,n2;
void insert_td(int x)
{
    while (x<=n2){
       ++d[x];x+=(x&(-x));
    }
}
void insert_te(int x)
{
    while (x<=n2){
       ++e[x];x+=(x&(-x));
    }
}
void  remove_td(int x)
{
    while (x<=n2){
            --d[x]; x+=(x&(-x));
    }
}
void  remove_te(int x)
{
    while (x<=n2){
            --e[x]; x+=(x&(-x));
    }
}
int sum_td(int x)
{
    int tg=0;
    while (x>0){
        tg+=d[x]; x&=(x-1);
    }
    return tg;
}
int sum_te(int x)
{
    int tg=0;
    while (x>0){
        tg+=e[x]; x&=(x-1);
    }
    return tg;
}
int main()
{ fi>>n; n2=n<<1; ix=0;
for (int i=1; i<=n;++i){
  fi>>a>>b;
  if (a>b) swap(a,b);
  c[a]=b;
  if (a>ix) ix=a;
  insert_td(a);
  insert_te(b);
}
 for (int i=1; i<=ix ; i++)
    if (c[i]){
        res+=sum_td(c[i])-sum_te(c[i]);
        remove_td(i); remove_te(c[i]);
    }
 fo<<res;
}
