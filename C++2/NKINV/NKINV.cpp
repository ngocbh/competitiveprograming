#include <iostream>
#include <stdio.h>
#include <cmath>
#define maxn 65000
#define maxa 65000
using namespace std;
int n,a[maxn],t[maxn],res=0;
void update(int x)
{
    while ( x > 0 ) {
        t[x] = t[x] + 1;
        x = x - (x & (-x) );
    }
}
void findres(int x)
{
    while ( x <= maxa ){
        res = res + t[x];
        x = x + (x & (-x) );
    }
}
int main()
{   //freopen("NKINV.inp","r",stdin);
    //freopen("NKINV.out","w",stdout);
        scanf("%d",&n);
        for (int i=1; i<=n; i++) scanf("%d",&a[i]);
        for (int i=1; i<=n; i++) {
            findres(a[i]+1);
            update(a[i]);
        }
    printf("%d",res);
}
