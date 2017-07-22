#include <bits/stdc++.h>

const long N = 100+10;
using namespace std;
int n,a[1],cs=0;
string s,s0,s1;
int main()
{   //freopen("P151SUMI.inp","r",stdin);
    scanf("%d", &n);    cin>>s0; ++a[0];
    for (int i = 1; i <= n; i++){
        cin>>s;
        if (s != s0) {
                s1 = s;
                ++a[1];
        } else {
                ++a[0];
        }
    }
    if ( a[1] > a[0] )
        cout<<s1;
    else
        cout<<s0;

}
