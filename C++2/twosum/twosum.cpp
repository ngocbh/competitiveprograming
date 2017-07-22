#include <iostream>
#include <stdio.h>
#include <vector>
#define maxn 5000+100
#define maxa 20000+200
using namespace std;
int n,a[maxn],f[maxn];

void xuly(int x)
{
    pair<int,int> cc[maxn];
    int aa[maxn],bb[maxn]
    for (int i=1; i<=n; i++) {
        cc[i].first=a[i]/x;
        cc[i].second=a[i]%x;
    }

}
int main()
{
    freopen("twosum.inp");
    freopen("twosum.out");
    cin>>n;
    for (int i=1; i<=n; i++) cin>>a[i];
    for (int i=1; i<=n; i++) f[i]=f[i-1]+a[i];
    ///===nhap;
    for (int k=2; k<=n-1; k++){
        xuly();
    }
}
