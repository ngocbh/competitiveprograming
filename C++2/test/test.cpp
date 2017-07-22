#include <bits/stdc++.h>

using namespace std;
ifstream fi("test.inp");
ofstream fo("test.out");
const long maxn=4*1000+10;
int n,t,a[maxn],f[maxn],x[maxn],kq1[maxn],a1[maxn],dem[maxn],h[maxn];
pair <int,int> ca[maxn];
int64_t res,sl;
void xetkq()
{
    if (sl<res) {
        res=sl;
        for (int i=1; i<=n; i++)
            kq1[i]=x[i];
    }


}
void try1(int i)
{   if (i>n){ xetkq(); return;}
    int64_t sl2;
   sl2=sl;
   if (sl>=res) return;
    for (int j=1; j<=n; j++)
     if (f[j]){
        x[i]=j;
        f[j]=false;
        dem[a[j]]--; sl=sl2;
        for (int l=1; l<i; l++)
                 sl+=dem[2*a[j]-a[x[l]] ];
        try1(i+1);
        f[j]=true;dem[a[j]]++;

    }
}
void div1(int l,int r)
{    int j1=0,mid,b[maxn];
if (r-l<=1) return;
for (int i=1; i<=r-l+1; i++)
    if (i%2==1) b[j1++]=h[l+i-1];
mid=(l+r)/2;
for (int i=1; i<=r-l+1; i++)
    if (i%2==0) b[j1++]=h[l+i-1];
for (int i=1; i<=r-l; i++)
    h[l+i]=b[i];
//for (int i=1; i<=n; i++) fo<<a[i]<<" "; fo<<endl;
div1(l,mid);
div1(mid+1,r);

}
void xuly1()
{  int mm=0;

    //================
    for (int i=1; i<=1001; i++) h[i]=i;
   for (int i=1; i<=n; i++)
   if (a[i]==h[i]) ++mm;
   if (mm==n){
    div1(1,n);
    for (int i=1; i<=n; i++) fo<<h[i]<<" ";
    fo<<endl;
    return;
   }
    div1(1,n);
    for (int i=1; i<=1001; i++)
    for (int j=1; j<=n; j++)
        if (a[j]+1==h[i])    fo<<j<<" ";
   fo<<endl;
}
void xuly()
{   memset(f,true,sizeof(f));
    memset(a,0,sizeof(a));
    memset(x,0,sizeof(x));
    memset(kq1,0,sizeof(kq1));
    memset(dem,0,sizeof(dem));
    fi>>n;
    res=1000000000;
    sl=0;
    for (int i=1; i<=n; i++) fi>>a[i];
    for (int i=1; i<=n; i++) ++dem[a[i]];
    //for (int i=1; i<=10; i++) fo<<dem[i]<<" ";
    if (n>1) {xuly1();return;}
    try1(1);
    for (int i=1; i<=n; i++ ) fo<<kq1[i]<<" ";
    fo<<endl;

}
int main()
{ fi>>t;
  for (int i=1; i<=t; i++) xuly();

}

