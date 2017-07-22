#include <bits/stdc++.h>

using namespace std;
ifstream fi("lineup.inp");
ofstream fo("lineup.out");
const long maxn=50000+100;
int n,res=1000000000,cc=0;
int64_t ta[maxn];
pair <int,int> a[maxn],la[maxn];
void chuanhoa()
{
    sort(la+1,la+n+1);
   // for (int i=1; i<=n; i++)
     // fo<<la[i].first<<" "<<la[i].second<<endl;
    for (int i=1; i<=n; i++)
        if (la[i].first!=la[i-1].first){
            ++cc;
            a[la[i].second ].second=cc;
        }
        else a[la[i].second].second=cc;
 for (int i=1; i<=n; i++)
     fo<<a[i].first<<" "<<a[i].second<<endl;
    sort(a+1,a+n+1);
   for (int i=1; i<=n; i++)
     fo<<a[i].first<<" "<<a[i].second<<endl;

}
void xuly()
{   int j=1;
    for (int i=1; i<=cc; i++) {
        ta[i]=-100000;
        ta[0]+=ta[i];
    }
    for (int i=1; i<=n; i++ )
    {   if (ta[a[i].second]<0) {ta[a[i].second]=1;ta[0]+=100001;}
        else {++ta[a[i].second];ta[0]+=1; }

        if (ta[0]>0){
            while (ta[a[j].second]>1) {  --ta[a[j].second ];    ++j;    }
            int kk;
            kk=a[i].first-a[j].first;
            if (kk<res) res=kk;
        }



    }
    fo<<res;
}
int main()
{
   fi>>n;
   for (int i=1; i<=n; i++) {
        fi>>a[i].first>>a[i].second;
        la[i].first=a[i].second;
        la[i].second=i;
   }
   chuanhoa();
   xuly();
}
