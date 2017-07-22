#include <bits/stdc++.h>

using namespace std;
long long t,n,sx,sy,ex,ey,bx,by;
int main()
{   //freopen("DEVJERRY.inp","r",stdin);
    cin>>t;
    while (t--) {
        cin>>n>>sx>>sy>>ex>>ey>>bx>>by;
        if ( (sx == ex && ex == bx && by > min(sy,by) && by < max(sy,by) ) || ( sy == ey && ey == by &&  bx > min(sx,bx) && bx < max(sx,bx) ) )  cout<< abs(sx-ex) + abs(sy-ey) + 2<<endl;
        else cout<<abs(sx-ex) + abs(sy-ey) <<endl;
    }

}
