#include <bits/stdc++.h>

using namespace std;
long long w,n,c,st[15]={0,1,1,1,2,1,2,2,2,3},sc[15]={1,1,1,1,2,1,2,1,1,3},resst,ressc,t;
void xuly()
{   resst=0; ressc=1;
    int64_t cc,w,rr;
    rr=5000*pow(10,c);
    cc=n/rr;
    if (cc!=0) cc--;
    if ((n%rr)!=n) w=(n%rr)+rr;
    else w=n%rr;
    while (w>0){
        int x;
        x=w%10;
        resst+=st[x];
        ressc*=sc[x];
        w=w/10;
    }
    cout<<resst+cc<<" "<<ressc<<endl;

}
int main()
{  freopen("atm.inp","r",stdin);
   freopen("atm.out","w",stdout);
    scanf("%lld",&t);
   // cin>>t;
    for (int i=1; i<=t; i++) {
           //scanf("%lld %lld",&n,&c);
           cin >> n >> c;
          // cout << n << " " << c <<endl;
            if ((n % 1000 != 0 ) || (n==0)) cout<<0<<endl;
            else
            xuly();
    }


}
