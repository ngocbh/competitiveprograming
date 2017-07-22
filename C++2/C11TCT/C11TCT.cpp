#include <bits/stdc++.h>
#define N 100000+3
#define ll long long
using namespace std;
const long C = 100000 + 3 ;
ll n,m,f[N],inv[N],am[20],an[20],res=0;

int cv_p(int x)
{
    ll  t,r=1,h,p;
    p=C-2 ; t = x ;
    while ( p > 0 ) {
        if ( p % 2 == 1 ) r = ( r * t ) % C ;
        t = ( t * t ) % C ;
        p = p / 2 ;
    }
    return r ;
}
void init()
{   f[0] = 1; inv[0] = 1;
    for (int i=1; i<=C; i++)
        f[i] = ( f[i-1] * i ) % C ;
       // f[0] = 0;inv[0] = 0;
    for (int i=1; i<=C; i++) inv[i] = cv_p( f[i] );
}
void init_a(ll m,ll n)
{
    memset(am,0,sizeof(am));
    memset(an,0,sizeof(an));
   // cout<<m<<" "<<n<<endl;
    ll t=1,mm=m,k;
    while ( mm > 0 ) {
        k=1; t=0;
        while ( mm >= (k*C) ) { k *= C; ++t; }
        am[t] = mm / k;
        if ( k == 1 ) break;
        mm = mm % k;
    }
    ll nn=n;
    while ( nn > 0 ) {
        k=1; t=0;
        while ( nn > ( k*C ) ) { k *= C; ++t; }
        an[t] = nn / k;
        if ( k == 1 ) break;
        nn = nn % k;
    }
   // for (int i=0; i<=10 ;i++) cout<<am[i]<<" "; cout<<endl;
   // for (int i=0; i<=10; i++) cout<<an[i]<<" "; cout<<endl;
}
void solve()
{   int i=0;
	res=1;
    while ( true ) {
        if ( am[i] > an[i] ) { res = 0; break; }
        if ( am[i] == 0 && an[i] == 0 ) break;
        //cout<<i<<" ";
        res= ( res * ((( inv[am[i]] * inv[an[i]-am[i]] ) % C ) * f[an[i]] ) % C ) % C  ;
        ++ i;
    }
    printf("%lld\n",res);


}
void inp()
{   int t;
    //freopen("C11TCT.inp","r",stdin);
    //freopen("C11TCT.out","w",stdout);
    scanf("%d",&t);
    while ( t-- ){
        scanf("%lld%lld", &m, &n);
        init_a(n,m-n+1);
        solve();
    }
}
int main()
{  init();
   inp();

}

