#include <bits/stdc++.h>

using namespace std;
int n,dem=0,cs=10;
string s="",sn;
string xss(int x)
{
    stringstream ss;
    ss<<x;
    return ss.str();
}
int main()
{   cin>>n;
    if (n==1) {cout<<1; return 0;}
    sn=xss(n);
    for (int i=1; i<=n; i++)
    { string s1;
      s1=xss(i);
      s=s+s1;
    }
     int m;
     m=s.find(sn);
     if (m>0)
    cout<<m+1;

}
