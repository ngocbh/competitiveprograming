#include <iostream>

using namespace std;
int n,l,r,x,a[20],xa[20];
int64_t res=0;
void ktkq()
{   int min1=1000000000+1,max1=0,sum1=0;
    for (int i=1; i<=n; i++)
        if ( xa[i] == 1 ){
        min1=min(min1,a[i]);
        max1=max(max1,a[i]);
        sum1+=a[i];
    }
    if ( sum1<=r && sum1 >=l && max1-min1>=x ) ++res;
}
void duyet(int i,int q)
{
    if ( i > q ) { ktkq(); return; }
    for (int j=0; j<=1; j++){
        xa[i] = j;
        duyet(i+1,q);
    }
}
int main()
{
    //freopen("B.inp","r",stdin);
    cin>>n>>l>>r>>x;
    for (int i=1; i<=n; i++ ) cin>>a[i];
    //for (int i=1; i<=n; i++)
    duyet(1,n);
    cout<<res;
}
