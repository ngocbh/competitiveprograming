#include <bits/stdc++.h>
//#define fi cin
//#define fo cout
using namespace std;
ifstream fi("vao.inp");
ofstream fo("ra.out");

const long maxn=1000000+100;
int n,m;
typedef pair <int,int> p2;
//typedef pair <int,p2> p3;
p2 a[maxn];
string s;
void left1()
{   int i,j,t;
    fi>>j>>i;
    t=a[i].first;
    a[i].first=j;
    a[j].second=i;
    a[t].second=j;
    a[j].first=t;
}
void right1()
{
    int i,j,t;
    fi>>j>>i;
    t=a[i].second;
    a[i].second=j;
    a[j].first=i;
    a[t].first=j;
    a[j].second=t;
}
void leave1()
{    int tl,tr,i,j;
    fi>>i;
    tl=a[i].first;
    tr=a[i].second;
    a[i].first=-1;
    a[i].second=-1;
    a[tl].second=tr;
    a[tr].first=tl;
}
void name1()
{   int i;
    fi>>i;
    fo<<a[i].first<<" "<<a[i].second<<endl;
}
int main()
{  //freopen("vao.inp","r",stdin);
   //freopen("ra.out","w",stdout);
    fi>>n>>m;
    // printf("%d",m);
    for (int i=1; i<=n; i++) { a[i].first=-1; a[i].second=-1;}
    a[1].first=0; a[1].second=0;
    a[0].second=1; a[n+1].first=1;
   // scanf("%d %d",&n,&m);
    for (int i=1; i<=m; i++){

        fi>>s;
        if (s=="left") left1();
        if (s=="right") right1();
        if (s=="leave") leave1();
        if (s=="name") name1();
      //  fo<<s<<endl;
    }

}
