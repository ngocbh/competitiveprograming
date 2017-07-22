#include <iostream>
#include <stdio.h>
#include <cmath>
#include <vector>
#include <algorithm>
#include <memory.h>
#define maxn 1000+10
#define x first
#define y second
using namespace std;
typedef pair <int,int> ii;
int a[maxn],c[maxn],cs[maxn],cc[maxn],sl[maxn],sc[maxn][maxn];
double s[maxn],ss[maxn],res;
bool ca[maxn];
int n,m,k,u,v;
vector <ii> p[maxn];
void inp()
{
    freopen("TFIELD.inp","r",stdin);
   // freopen("TFIELD.out","w",stdout);
    scanf("%d %d",&m,&k);
    for (int i=1; i<=m; i++) {
        int ca;
        scanf("%d %d",&n,&ca);
        a[i]=n; c[i]=ca;
        for (int j=1; j<=n; j++) {
                scanf("%d %d", &u,&v );
                p[i].push_back( ii(u,v) );
        }
    }
}
double c_area(int x)
{   n=p[x].size()-1;
    double c=0;
    p[x].push_back(p[x][0]);
    for (int i=0; i<=n; i++)
        c+=(p[x][i].x - p[x][i+1].x)*(p[x][i].y + p[x][i+1].y);
    return abs(c)/2;
}
bool cmp(int i,int j)
{
    return s[i] < s[j];
}
void init()
{
    for (int i=1; i<=m; i++) cs[i]=i;
    p[0].push_back(ii(0,0));
    for (int i=1; i<=m; i++)
        s[i]=c_area(i);
    ///===== sort;
    for (int i=1; i<=m; i++) ss[i]=s[i];
    for (int i=1; i<=m; i++) cc[i]=c[i];
    sort(cs+1,cs+m+1,cmp);
    for (int i=1; i<=m; i++) s[i]=ss[cs[i]];
    for (int i=1; i<=m; i++) c[i]=cc[cs[i]];
    s[0]=0;
    for (int i=m; i>=1; i--) s[i]=s[i]-s[i-1];
//    for (int i=1; i<=m; i++) cout<<sf[i]<<" ";
    //for (int i=1; i<=m; i++) cout<<s[i]<<" ";
    for (int i=1; i<=m; i++) {
        for (int j=1; j<=m; j++)
            if ( c[i]==j ) sc[i][j]=sc[i-1][j]+1;
            else sc[i][j]=sc[i-1][j];
    }

}

void solve()
{   int caa[maxn];
    for (int i=1; i<=m ;i++)
        for (int j=i; j<=m; j++) {
            memset(ca,true,sizeof(ca));
            int ssl=0,sx=0,sy=0,slx=0,sly=0;
            for (int o=i; o<=j; o++)
                if ( ca[c[o]] ){
                    ++ssl;
                    ca[c[o]]=false;
                    if ( sx==0 )sx=c[o];
                    if ( sx ) sy=c[o];
                }
            if ( ssl>2 ) continue;
            for (int o=i; o<=j; o++)
                if ( c[o]==sx ) ++slx;
            for (int o=i; o<=j; o++)
                if ( c[o]==sy ) ++sly;
            if ( slx<=k || sly<=k ) {
                double ress=0;
                for (int o=i; o<=j; o++)
                    ress+=s[o];
                res=max(res,ress);
            }

        }
        printf("%0.1f",res);
}
int main()
{
    inp();
    init();
    solve();
}

