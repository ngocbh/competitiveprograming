#include <iostream>
#include <stdio.h>

using namespace std;
const long maxn=1000+10;
const long maxxx=20000+200;
int t,n,x,y,f[maxn][2*maxxx],x1[maxn],x2[maxn],h[maxn],maxx;
void sort1()
{
    for (int i=1 ; i<=n-1; i++)
     for (int j=i+1; j<=n; j++){
        if (h[i]<h[j]){
            swap(h[i],h[j]);
            swap(x1[i],x1[j]);
            swap(x2[i],x2[j]);
        }
    }
}
void xuly()
{
    cin>>n>>x>>y>>maxx;
    for (int i=1; i<=n; i++)    {cin>>x1[i]>>x2[i]>>h[i]; x1[i]+=20000; x2[i]+=20000; }
    sort1();
    //for (int i=1; i<=n; i++) cout<<x1[i]<<" "<<x2[i]<<" "<<h[i]<<endl;
    for (int i=1; i<=n; i++){
        int xx,yy;
        xx=x1[i]; yy=x2[i];
        for (int j=i-1; j>=0; j--)
        if (h[j]-h[i]<=maxx)
        {
            if (x1[j]<=yy && x1[j]>=xx ){
                f[i][x1[i]]=min(f[j][x1[j]]+(h[j]-h[i])+x1[j]-x1[i],f[i][x1[i]]);

                f[i][x2[i]]=min(f[j][x1[j]]+(h[j]-h[i])+x1[j]-x2[i],f[i][x2[i]]);

                yy=x1[j];
            }
            if (x2[j]<=yy && x2[j]>=xx ){
                f[i][x1[i]]=min(f[j][x2[j]]+(h[j]-h[i])+x2[j]-x1[i],f[i][x1[i]]);

                f[i][x2[i]]=min(f[j][x2[j]]+(h[j]-h[i])+x2[j]-x2[i],f[i][x2[i]]);

                xx=x2[j];
            }
        }
        else break;

    }
}
int main()
{  freopen("mickey.inp","r",stdin);
   freopen("mickey.out","w",stdout);
   cin>>t;
    while (t--) {
            int tt;
            cin>>tt;
            while (tt--)
            xuly();
    }

}
