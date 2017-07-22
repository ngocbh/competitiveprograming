#include <bits/stdc++.h>

using namespace std;
int n,min1,min2,min3,max1,max2,max3,a,b,c;
int main()
{   //freopen("A.inp","r",stdin);
    cin>>n;
    cin>>min1>>max1;
    ///bbbbbbbbbbbbbbbbbbbbbbb
    cin>>min2>>max2;
    cin>>min3>>max3;
    ////bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb
    a = min1;
    b = min2;
    c = min3;
    if ( n - b - c <= max1 ) { cout<<n-b-c<<" "<<b<<" "<<c; return 0; }
    ///bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb
    a = max1;
    if ( n - c - a <= max2 ) { cout<<a<<" "<<n-a-c<<" "<<c; return 0; }
    ///bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb
    b = max2;
    if ( n - a - b <= max3 ) {cout<<a<<" "<<b<<" "<<n-b-a; return 0; }
    ///bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb
    c = max3;
    cout<<a<<" "<<b<<" "<<c;
}
