#include <bits/stdc++.h>

using namespace std;
ifstream fi("abcd.inp");
ofstream fo("abcd.out");
int a,b,c,d,res,a1,b1,c1,d1;
int main()
{
    fi>>a;
    fi>>b;
    fi>>c;
    fi>>d;
   res=0;
    while (1==1){
        //if (res==10) break;
        int t;
        t=a;
        if (a==0 && b==0 && c==0 && d==0) break;
        a=abs(a-b);
        b=abs(b-c);
        c=abs(c-d);
        d=abs(d-t);
        ++res;
    }
    fo<<res;
}
