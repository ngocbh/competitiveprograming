#include <bits/stdc++.h>
const long N = 100000+10;
using namespace std;
int t,n,af[N],as[N],sp[N],x,res,min1,max1,mi,ma,cs[N];
vector <int> p1,p2;
bool cmp(int i,int j)
{
    return sp[i] < sp[j];
}
int main()
{   freopen("DEVSHOW.inp","r",stdin);
    scanf("%d",&t);
    while (t--){
        scanf("%d",&n);
        res=0;
        for (int i=1; i<=n; i++) sp[i] = 0;
        for (int i=1; i<=2*(n-2); i++)
        {
            scanf("%d",&x);
            ++sp[x];
        }
        sort(cs+1,cs+n-1,cmp);
        if ( sp[n-1] > sp[cs[1]] && sp[cs[n-2]] > sp[n-1] ) ++res;
        if ( sp[n] > sp[cs[1]] && sp[n] < sp[cs[n-2]] ) ++res;
        if ( sp[n-1] == sp[cs[n-2]] ) {
            ++res;
            p1.push_back(cs[n-2]);
        }
        if ( sp[n] == sp[cs[n-2]] ) {
            ++res;
            p2.push_back(cs[n-2]);
        }
        if ( sp[n-1] == sp[cs[n-2]]+1 )
            if ( p1.size() == 0 ){
            ++res;
            p2.push_back(cs[n-2]);
            p1.push_back(cs[n-2]);
        } else
            if (  p2[0] != cs[n-2] ){
            ++res;
            p2.push_back(cs[n-2]);
            p1.push_back(cs[n-2]);
        }
        if ( sp[n] == sp[cs[n-2]]+1  )
            if ( p2.size() == 0 ){
            ++res;
            p2.push_back(cs[n-2]);
           p1.push_back(cs[n-2]);
        } else if ( p2[0] != cs[n-2] ) {
            ++res;
            p2.push_back(cs[n-2]);
           p1.push_back(cs[n-2]);
        }
        p1.push_back(cs[n-3]); p1.push_back(cs[n-2]);
        p2.push_back(cs[n-3]); p2.push_back(cs[n-2]);
        cout<<res<<endl;
    }

}
