#include <bits/stdc++.h>
///C chu k phai B
using namespace std;
int n,k,sl,sc,sls,sld,a;
int main()
{  // freopen("B.inp","r",stdin);
    scanf("%d %d" ,&n,&k);
    sls = (n-k+1)/2;
    sld = (n-k)/2;
    for (int i=1 ; i<=n; i++) {
        scanf("%d" , &a);
        if ( a % 2 == 0 ) ++sc;
        else ++sl;
    }
    if ( sld > sl ) { cout<<"Daenerys"; return 0; }
    if ( sls == sld ) {
        if ( sl % 2 == 0 ) { cout<<"Stannis"; return 0; }
        else { cout<<"Daenerys"; return 0; }
    }
    { cout<<"Stannis"; return 0; }
}
