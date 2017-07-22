#include <iostream>
#include <stdio.h>
#include <cmath>
#include <memory.h>
#include <vector>
#define maxn 1000000+100
#define maxa 1000000000+7
using namespace std;
int n,a[maxn],l[maxn],f[maxn],b[maxn],ta[maxn],cs[maxn],kq[maxn];
vector <int> ls[maxn];
int tim(int x,int n)
{
    int l=1, r=n , res=0;
    while ( l <= r ){
        int mid;
        mid=(l+r)/2;
        if ( b[mid] < x ) res=mid,l=mid+1;
        else r=mid-1;
    }
    return res;
}
void dctdn()
{   int res=0,k=0,nho;
    for (int i=1; i<=n; i++) {
        int m;
        m=tim(a[i],k);
        if ( m < k   ) {
                //if ( a[i] <=b[m+1] ) continue;
                b[m+1]=a[i];
                cs[m+1]=i;
                f[i]=m+1;
                if ( res <= f[i]  ) { res=f[i]; nho=i;  }
                ta[i]=cs[m];
                ls[m+1].push_back( i );
        } else
          {if (m==k) {
                ++k;
                cs[k]=i;
                b[k]=a[i];
                f[i]=k;
                ta[i]=cs[k-1];
                if ( res <= f[i]  ) { res=f[i]; nho=i;  }
                ls[k].push_back( i );
        }}
    } int i=0,u=nho,max1=0;
    cout<<res<<endl;
    for (int i=0; i<= ls[res].size()-1; i++ )
        if ( max1 < a[ ls[res][i] ] ) {
            max1=a[ls[res][i]];
            nho=ls[res][i];
        }
    kq[res]=nho;
    for (int i=res-1; i>=1; i--) {
        int max1=-1,v,nnho=0;
        for (int j=0; j<=ls[i].size()-1; j++ ) {
            v=ls[i][j];
            if ( a[v] > max1 && v<=nho && a[v]<a[nho] ) { max1=a[v]; nnho=v;  }
        }
        nho=nnho;
        kq[i]=nnho;
    }
    for (int i=1; i<=res; i++) printf("%d\n",a[kq[i]]);
}
int main()
{   freopen("INCSEQ.inp","r",stdin);
    freopen("INCSEQ.out","w",stdout);
    scanf("%d",&n);
    for (int i=1; i<=n; i++) scanf("%d",&a[i]);
    a[0]=-1;
    for (int i=1; i<=n; i++) ls[i].push_back(0);
    a[0]=0;
    dctdn();

}
