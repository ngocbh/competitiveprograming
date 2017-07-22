#include <iostream>
#include <stdio.h>
#include <string>
#include <cmath>
#include <algorithm>
#include <memory.h>
#define maxn 100000+100
//#define maxx 1000000000+7
using namespace std;
int64_t n,a[maxn],f[maxn],maxx=0,cs[maxn];
int aaa[20]={1,10,100,1000,10000,100000,1000000,10000000,100000000,1000000000};
string aa[maxn];
int xsn(char c)
{
    return (int )( c-'0' );
}
char nsx(int x)
{
    return ( char ) ( x+48 );
}
int ssn(string s)
{   int aa=0;
    for (int i=0; i<=s.size()-1; i++)
            aa=aa*10+xsn(s[i]);
    return aa;
}
string nss(int x)
{   string s;
    while ( x>0 ) {
        s=nsx( x % 10 ) +s;
        x=x/10;
    }
    return s;
}
void khoitao()
{   string s1;
    for (int i=1; i<=n; i++)
        aa[i]=nss(a[i]);
    /*int nn;
    s1=nss(maxx);
    nn=s1.size();
    for (int i=1; i<=n; i++) {
        int ii;    ii=aa[i].size();
        aa[i].insert( ii-1,nn-ii, aa[i][0] );
    }*/
}
int ll(int x)
{
    int u; u= (int) log10(x);
    return aaa[u+1];
}
bool cmp(int i,int j)
{
    return  a[i]*ll(a[j]) +a[j]  > ( a[j]*ll(a[i]) + a[i] ) ;
}
int main()
{   freopen("maxnum.inp","r",stdin);
    freopen("maxnum.out","w",stdout);
    scanf("%d",&n);
    for (int i=1; i<=n; i++) { scanf("%d",&a[i]); maxx=max(maxx,a[i]); cs[i]=i; }
    khoitao();
    sort(cs+1,cs+n+1,cmp);
    for (int i=1; i<=n; i++) printf("%d",a[cs[i]]);
}
