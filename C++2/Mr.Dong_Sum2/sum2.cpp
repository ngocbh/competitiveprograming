#include <fstream>

using namespace std;
ifstream fi("sum2.inp");
ofstream fo("sum2.out");
const long oo=1000000;
int64_t t,n;
void xuly(int64_t x)
{
    int64_t kq=0;
    int64_t i=0,j=0,v=2212;
   // fo<<x;
    while (v>1)
    {
        i=j+1;
        v=x/i;
        j=x/v;
        kq=(kq+v*(j-i+1))%oo;
    }
    fo<<kq<<endl;
}
int main()
{ fi>>t;// fo<<t;
 for (int i=1; i<=t; i++){
     fi>>n;
     xuly(n);
 }
}
