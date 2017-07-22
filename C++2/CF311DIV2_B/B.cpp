#include <bits/stdc++.h>
const long N = 100000 + 10;
using namespace std;
int64_t n;
int64_t w;
int64_t a[2*N];
int main()
{
    scanf("%d %d",&n,&w);
    for (int i = 1; i <= 2*n; i++) scanf("%d",&a[i]);
    sort(a+1,a+2*n+1);
    if ( a[1] * 2 <= a[n+1] )  {
        if ( w > n*a[1]*3 ) cout<<n*a[1]*3;
        else cout<<w;
    }
    else {
         {
        if ( w > n*a[n+1]*3/2 ) cout<< (float) n*a[n+1]*3/2;
        else cout<<w;
    }
    }
}
