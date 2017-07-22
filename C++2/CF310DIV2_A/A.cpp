#include <bits/stdc++.h>

using namespace std;

int main()
{
    char c;
    int n,s0=0,s1=0;
    cin>>n;
    for (int i = 1; i <= n; i++){
        cin>>c;
        if ( c == '0' ) ++s0;
        else ++s1;
    }
    cout<<n - min(s0,s1) * 2;
}
