/*#include <iostream>
#include <stdio.h>
using namespace std;
int64_t a,b,res=0,ba;
int64_t p[60]={1,1,2,3,2,5,1,7,2,3,1,11,1,13,1,1,2,17,1,19,1,1,1,23,1,5,1,3,1,29,1,31,2,1,1,1,1,37,1,39,1,41,1,43,1,1,1,47,1,1};
int64_t strenght(int64_t n)
{   int64_t c;
    if ( n == 2 ) return 1;
    for (int i=1; i<=n; i++ ) if ( n % i != 0 ) { c=i; break; }
    return strenght(c)+1;
}
int64_t g(int64_t n)
{   int64_t m=n,i=2,mm=3;
    res=0;
  //  cout<<n<<endl;
   // if ( n < mm ) return 0;
    if ( n == 2 ) return 3;
    while ( m > 0 ) {
        if ( p[i] == 1 )  { ++i; continue; }
        int64_t cs;
        cs=( m - mm ) / p[i];
        if ( m % p[i] == 0 || mm % p[i] == 0 ) ++cs;
        res+=(m - mm + 1 -cs) * (strenght(i)+1);
        m=m/p[i];
        mm=mm/p[i];
        ++i;
    }
    return res;
}
int main()
{   freopen("strenght.inp","r",stdin);
    freopen("strenght.out","w",stdout);
    cin>>a>>b;
    cout<<g(b)-g(a-1)<<endl;
   //res=0; for (int i=a; i<=b; i++) res+=strenght(i); cout<<res;
}*/
///====cach khong de quy dung';
///====cach de quy;
#include <iostream>
#include <stdio.h>
using namespace std;
int64_t a,b,res=0,ba;
int64_t p[60]={1,1,2,3,2,5,1,7,2,3,1,11,1,13,1,1,2,17,1,19,1,1,1,23,1,5,1,3,1,29,1,31,2,1,1,1,1,37,1,39,1,41,1,43,1,1,1,47,1,1};
int strenght(int n)
{   int c;
    if ( n == 2 ) return 1;
    for (int i=1; i<=n; i++ ) if ( n % i != 0 ) { c=i; break; }
    return strenght(c)+1;
}
int64_t g(int n,int x)
{
    if ( n == 0 ) return 0;

}
int main()
{   freopen("strenght.inp","r",stdin);
    freopen("strenght.out","w",stdout);
    cin>>a>>b;
    cout<<g(b,2)-g(a,2);
}
