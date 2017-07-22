#include <bits/stdc++.h>

const long N = 100000 + 10;
using namespace std;

int n,a[N],b[N],c[N];
int res,bi1,ci1,bi2,ci2,bb1,cc1,bb2,cc2;
int main()
{   freopen("PHIM.inp","r",stdin);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d %d %d", &a[i], &b[i], &c[i]);
    for (int i = 1; i <= n; i++) {
        res += a[i];
        if ( b[i] - a[i] > bb1 ) bb1 = b[i] - a[i],bi1 = i;
        else
            if ( b[i] - a[i] > bb2 ) bb2 = b[i] - a[i],bi2 = i;
        if ( c[i] - a[i] > cc1 ) cc1 = c[i] - a[i],ci1 = i;
        else
            if ( c[i] - a[i] > cc2 ) cc2 = c[i] - a[i],ci2 = i;
    }
    if ( bi1 != ci1 ) {
        cout<<res + bb1 + cc1<<endl;
        cout<<bi1<<" "<<ci1;
        return 0;
    } else {
        if ( bb1 + cc2 > bb2 + cc1 ) {
        cout<<res + bb1 + cc2<<endl;
        cout<<bi1<<" "<<ci2;
        } else {
        cout<<res + bb2 + cc1<<endl;
        cout<<bi2<<" "<<ci1;
        }
    }

}
