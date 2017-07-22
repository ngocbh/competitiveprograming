#include <iostream>
#include <stdio.h>
#include <cmath>
#include <stdio.h>
#define maxn 1000000+100
#define maxa 1e9+7
using namespace std;
int n,a[maxn],fa[2][maxn],maxx;
int64_t res=0;
void xuly()
{   int nn=n-1;
    for (int i=1; i<=n-1; i++) fa[0][i]=max(a[i],a[i+1]);
    int ic=0,im=1;
    for (int i=1; i<=n-1; i++) {
       // for (int o=1; o<=nn; o++) cout<<fa[ic][o]<<" "; cout<<endl;
        int min1=maxa,nho;
        for (int j=1; j<=nn; j++)
            if ( fa[ic][j] < min1 ) {
                min1=fa[ic][j];
                nho=j;
            }
    //cout<<min1<<" "<<nho<<" ";
        res+=min1; //cout<<res<<endl;
        fa[ic][nho-1]=max(min1,fa[ic][nho-1]);
        fa[ic][nho+1]=max(min1,fa[ic][nho+1]);
        int ii=0;
        for (int o=1; o<=nn;o++)
            if ( o==nho ) continue;
            else  fa[im][++ii]=fa[ic][o];
       // for (int o=1; o<=nn; o++) cout<<fa[im][o]<<" "; cout<<endl;
        ic=1-ic;
        im=1-im;
        --nn;
    }
    cout<<res;
}
int main()
{   freopen("SEQ.inp","r",stdin);
    freopen("SEQ.out","w",stdout);
    scanf("%d",&n); maxx=-maxa;
    for (int i=1; i<=n; i++) {scanf("%d",&a[i]);
        maxx=max(a[i],maxx);
    }
    xuly();
}
