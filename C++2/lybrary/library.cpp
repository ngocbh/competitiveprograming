#include <iostream>
#include <stdio.h>

using namespace std;
const long maxn=10000+100;
int t,n,a[maxn],cs[maxn],res;
void xuly()
{   res=0;
    cin>>n;
    for( int i=1; i<=n; i++ ) {cin>>a[i]; cs[a[i]]=i;}
   // for (int i=1; i<=n ;i++ ) cout <<cs[i]<<" ";
    for (int i=n; i>=1; i--){
        // if (cs[i]==i) continue;
         for (int j=cs[i]+1; j<=i; j++){
            swap(a[j-1],a[j]);
            swap(cs[a[j-1]],cs[a[j]]);
            ++res;
         }
    }
    //for (int i=1; i<=n ;i++ ) cout <<cs[i]<<" ";
    cout<<res<<endl;
}
int main()
{
   //freopen("library.inp","r",stdin);
   //freopen("library.out","w",stdout);
   cin>>t;
   while (t--) xuly();

}
