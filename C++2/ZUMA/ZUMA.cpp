#include <bits/stdc++.h>

const long N = 100 + 10;
using namespace std;

int n,res,a[N],vt,mb,dd,dc,st,sp,cz[5];
char c;
int main()
{   //freopen("ZUMA.inp","r",stdin);
    cin>>n;
    for (int i = 1; i <= n; i++){
        cin>>c;
        if ( c == 'X' ) a[i] = 1;
        if ( c == 'D' ) a[i] = 2;
        if ( c == 'T' ) a[i] = 3;
        if ( c == 'V' ) a[i] = 4;
    }
    cin>>vt>>c;
    if ( c == 'X' ) mb = 1;
    if ( c == 'D' ) mb = 2;
    if ( c == 'T' ) mb = 3;
    if ( c == 'V' ) mb = 4;
    ///========================
    int i = dc = vt,diem = 0;
    while ( a[i] == mb ) { ++i; ++sp; ++dc;  } i = vt-1; dd = vt - 1;
    while ( a[i] == mb ) { --i; ++st; --dd;  }
    if ( sp + st >= 2 ) { res += sp + st + 1; diem = 1; }
    if ( a[dd] != mb ) ++dd;
    if ( a[dc] != mb ) --dc;
    //cout<<dd<<" "<<dc<<" "<<res<<endl;
    while ( diem ) {
                memset(cz,0,sizeof(cz));
                int dc1=dc,dd1=dd;

                i = dd -1;
                while ( a[i] == a[dd-1] ) ++cz[a[dd-1]],--i,--dd1;
                i = dc +1;
                while ( a[i] == a[dc+1] ) ++cz[a[dc+1]],++i,++dc1;
                //cout<<dd1<<" "<<dc1<<endl;
                if ( a[dd -1] == a[dc+1] && cz[a[dd-1]] >= 3 && a[dd-1] != 0 ) { res += cz[a[dd-1]]; }
                else diem = 0;
                dd = dd1; dc = dc1;
                //cout<<dd<<" "<<dc<<" "<<res<<endl;
    }
    cout<<res;
}
