#include <bits/stdc++.h>

using namespace std;
const long maxn=100000+100;
int n,kq;
bool f[maxn];
pair <int,int> a[maxn];
int tim(int x)
{
    int l=1,r=n,res=0;
    while (l<=r){
        int mid;
        mid=(l+r)/2;
        if (a[mid].first<x) res=mid,l=mid+1;
        else r=mid-1;
    }


    if (a[res].first==x) return res;
    if (a[res+1].first==x) return res+1;
    return 0;
}
int main()
{
    freopen("lem5.inp","r",stdin);
    freopen("lem5.out","w",stdout);
    scanf("%d",&n);
    for (int i=1; i<=n; i++) {scanf("%d",&a[i].first); a[i].second = i;}
    sort(a+1,a+n+1);
    memset(f,true,sizeof(f));
    for (int d=1; d<=100; d++)
    for (int i=1; i<=n; i++)
        if (f[i]){
                int m,kq1,nho; m=a[i].first;
                while (tim(m)!=0){

                }
        }

    // int m;m=tim(3);printf("%d \n",m);
    // for (int i=1; i<=n; i++) printf("%d ",a[i].first);
}
