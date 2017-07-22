#include <iostream>
#include <stdio.h>
#include <cmath>
#include <memory.h>
#define maxn 100000+10
using namespace std;
int n,m,a[maxn],p[maxn],ca[maxn],x[maxn],kq[maxn],pp[maxn];
void ktkq()
{
    for (int i=1; i<=n; i++) {
        int r=0;
        for (int j=i-1; j>=1; j--)
            if ( x[j]>x[i] ) ++r;
        if ( r!=p[i] ) return;
    }
    for (int i=1; i<=n; i++) kq[i]=x[i];
}
void duyet(int i)
{   if ( i > n ) { ktkq(); return; }
    for (int j=1; j<=n; j++)
        if ( ca[j] ) {
            x[i]=j;
            ca[j]=false;
            duyet(i+1);
            ca[j]=true;
        }
}
void solve1()
{   cin>>n;
    for (int i=1; i<=n; i++)
        cin>>a[i];
    for (int i=1; i<=n; i++) {
        int r=0;
        for (int j=i-1; j>=1; j--)
            if ( a[j]>a[i] ) ++r;

        p[i]=r;    }
    for (int i=1; i<=n; i++) cout<<p[i]<<" ";
    cout<<endl;
}
void solve2()
{   memset(ca,true,sizeof(ca));
    cin>>n;
    for (int i=1; i<=n; i++) cin>>p[i];
    duyet(1);

    for (int i=1; i<=n; i++) cout<<kq[i]<<" ";
    cout<<endl;
}
int main()
{     freopen("PERMU.inp","r",stdin);
      freopen("PERMU.out","w",stdout);
      int t;cin>>t;
      while ( t-- ) {
            int loai;
            cin>>loai;
            if ( loai==1 ) solve1();
            else solve2();
       }

}
