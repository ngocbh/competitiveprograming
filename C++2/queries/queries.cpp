#include <fstream>
#include <vector>
using namespace std;
ifstream fi("queries.inp");
ofstream fo("queries.out");
const long maxn=100000+100;
vector <pair<int,int> > b,tp;
pair <int,int> ep,eb;
int n,m=-1,a[2*maxn];
///==========================
void new_el()
{
    tp.push_back(ep);
    b.push_back(eb);
    ++m;
}
///==========================
void insert_tb(int64_t x)
{
    int p=0,q,k=5,tg;
    for (int j=k; j>=0; --j){
        tg=(x>>j) & 1;
        if (tg) {
            q=tp[p].second;
            ++b[p].second;
            if (q<0 && j!=0) { new_el();
            tp[p].second=m; q=m; }
            else {
                q=tp[p].first; ++b[p].first;
                if (q<0 && (j!=0)){ new_el();tp[p].first=m; q=m; }
            }
        p=q;
        }
    }
}
void truy3()
{

}
void remove_tb()
{

}
int main()
{  fi>>n;
    for (int i=1; i<=n; i++) fi>>a[i];
   for (int i=1; i<=n; i++) insert_tb(a[i]);
   fi>>m;
   for (int i=1; i<=m; i++) {
     int loai;
     if ( loai==2) { int x; fi>>x; insert_tb(x); }
     if ( loai==1)  remove_tb();
     if ( loai==3)  truy3();
   }

}
