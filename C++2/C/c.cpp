#include <iostream>
#include <stdio.h>
#include <memory.h>
#include <algorithm>
#define maxn 100000+1000
using namespace std;
int n,m,a[maxn],b[maxn],res=0,nm,kqa=0,kqb=0;
int tim(int x)
{
    int l=1,r=m,res=0;
    while (l<=r){
        int mid;
        mid=(l+r)/2;
        if (b[mid]<=x) res=mid,l=mid+1;
        else r=mid-1;
    }
    return res;
}
int main()
{   //freopen("c.inp","r",stdin);
    //freopen("c.out","w",stdout);
    cin>>n;
    for (int i=1; i<=n; i++) cin>>a[i];
    cin>>m;
    for (int i=1; i<=m; i++) cin>>b[i];
    sort(a+1,a+n+1);
    sort(b+1,b+m+1);
    for (int i=1; i<=n; i++){
        int mm;
        mm=tim(a[i]-1);
        int resa,resb;
        resa=(i-1) * 2 + (n-i+1) * 3;
        resb=mm*2 + (m-mm) *3;
        //cout<<mm<<endl;
        if (resa-resb>res) {
            res=resa-resb;
            kqa=resa;
            kqb=resb;
        }
        if (resa-resb==res && resa>kqa) { res=resa-resb;
            kqa=resa;
            kqb=resb; }
        mm=tim(a[i]);
        resa=(i) * 2 + (n-i) * 3;
        resb=mm*2 + (m-mm) *3;
        //cout<<mm<<endl;
        if (resa-resb>res) {
            res=resa-resb;
            kqa=resa;
            kqb=resb;
        }
         if (resa-resb==res && resa>kqa) { res=resa-resb;
            kqa=resa;
            kqb=resb; }


    }
    cout<<kqa<<":"<<kqb;
}
