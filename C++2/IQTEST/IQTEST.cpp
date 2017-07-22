#include <bits/stdc++.h>

const long N = 1000 + 10;
using namespace std;
float u1,u2,u3,u4;
int main()
{   freopen("IQTEST.inp","r",stdin);
    freopen("IQTEST.out","w",stdout);
    scanf("%f %f %f %f ", &u1, &u2, &u3, &u4);
    if ( u4 - u3 == u3 - u2 && u3 - u2 == u2 - u1 ) {
        cout<<u4 + u4 - u3;
        return 0;
    }
    //if ( u4 % u3 !=0 || u3 % u2 != 0 && u2 % u1 != 0 ) { cout<<42; return 0; }
    if ( u4/u3 == u3/u2 && u3/u2 == u2/u1 ) {
        if ( (u4*u4/u3) != (int) (u4*u4/u3) ) cout<<42;
            else
                cout<<u4*u4/u3;
        return 0;
    }
    cout<<42;
}
