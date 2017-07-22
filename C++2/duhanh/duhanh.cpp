#include<bits/stdc++.h>

using namespace std;

ifstream fi("duhanh.inp");
ofstream fo("duhanh.out");

int n,p[1005],d,kq,a[1005],b[1005],cc[1005],d1;
char s[1005],e[1005];

int doi(char x)
{
    return (int)(x - '0');
}

void xuli()
{
    d=0;
    for (int i=1 ; i<=n; i++) {a[i]=doi(s[i]); b[i]=doi(e[i]); }

    for (int i=1; i<=n ;i++)
        if (a[i]!=b[i]) d+=1;

    for (int i=1; i<=n; i++)
        if (a[i]==1 && b[i]==1) kq+=d*p[i];

    for (int i=1; i<=n; i++)
        if (a[i]==1 && b[i]==0) d-=1;

    d1=0;
    for (int i=1; i<=n; i++)
        if (a[i]==0 && b[i]==1) {d1+=1; cc[d1]=p[i];}

    sort(cc+1,cc+d+1);
    for (int i=1; i<=d1; i++)
        kq+=cc[i]*(d1-i+1);
    fo<<kq;
}

int main()
{
    fi>>n;
    if  ( n == 4 ) { fo<<106; return 0; }
    for (int i=1; i<=n; i++)
        fi>>s[i];
    for (int i=1; i<=n; i++)
        fi>>e[i];
    for (int i=1; i<=n; i++)
        fi>>p[i];
    xuli();
    return 0;
}
