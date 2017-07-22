#include <bits/stdc++.h>

const long N = 2*100000 + 10;
using namespace std;

int n,f[8*N],t[8*N],ls,ans;
char s[N];

void update(int k,int l,int r,int u,int v)
{

    f[k] += ( l - r + 1 ) * t[k];
    t[2*k] += t[k];
    t[2*k+1] += t[k];
    t[k] = 0;
    if ( v < l || u > r ) return;
    if ( u <= l && v >= r ) {
        t[k] += 1;
        return;
    }
    int mid = (l+r)/2;
    update(2*k,l,mid,u,v);
    update(2*k+1,mid+1,r,u,v);
}

void visit(int k,int l,int r,int u)
{
    f[k] += ( l - r + 1 ) * t[k];
    t[2*k] += t[k];
    t[2*k+1] += t[k];
    t[k] = 0;
    if ( l > u || r < u ) return;
    if ( l == r && l == u ) {
        ans = f[k];
        return;
    }
    int mid = (l+r)/2;
    visit(2*k,l,mid,u);
    visit(2*k+1,mid+1,r,u);
}

int main()
{   //freopen("P151SUMF.inp","r",stdin);
    scanf("%s", &s); ls = strlen(s);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++){
        int a;
        scanf("%d", &a);
        update( 1 , 1 , ls , a , ls - a + 1);
    }
    for (int i = 1; i <= (ls+1)/2; i++) {
        ans = 0;
        visit(1,1,ls,i);
        if ( ans % 2 == 1 ) swap(s[i-1],s[ls-i]);
    }
    printf("%s\n", s);

}
