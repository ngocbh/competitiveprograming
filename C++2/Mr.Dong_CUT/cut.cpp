#include <fstream>

using namespace std;
ifstream fi("cut.inp");
ofstream fo("cut.out");
int t;
uint64_t a,b,c,d;
void sort1()
{
    if (a>b) swap(a,b);
    if (a>c) swap(a,c);
    if (b>c) swap(b,c);
}
void xuly()
{   // fo<<a<<b<<c;
    if (c-b>=d)         { fo<<(c-d)*b*a<<endl; return; }

     d=d-(c-b); c=b;
    if (2*(b-a)>=d)     {fo<<a*(b-(d+1)/2)*(c-d/2)<<endl; return;    }

     d=d-(2*(b-a));b=a;c=a;
    if ( 3*a>=d )       { fo<<(a-(d+2)/3)*(a-(d+1)/3)*(a-d/3)<<endl; return; }

    fo<<0<<endl;

}

int main()
{  fi>>t;
for (int i=1; i<=t; i++){
     fi>>a>>b>>c>>d;
     sort1(); /// sap xep lai 3 canh
     xuly();
}

}
