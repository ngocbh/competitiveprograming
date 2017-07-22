#include <bits/stdc++.h>

const long N = 100+10;
using namespace std;
int n,res,cs;
string a[N];
int main()
{   freopen("B.inp","r",stdin);
    cin>>n;
    for (int i = 1; i <= n; i++)
        cin>>a[i];
    sort(a+1,a+n+1);
    for (int i = 1; i <= n+1; i++) {
        if ( a[i] == a[i-1] ) ++cs;
        else {
            res = max(cs,res);
            cs = 1;
        }
    }
    cout<<res;
}
