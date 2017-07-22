#include <iostream>
#include <stdio.h>
#include <cmath>
#include <memory.h>
#include <algorithm>
#define maxn 1000+100

using namespace std;
int n,a[3][maxn],ca[maxn],cs[maxn];
string aa[3][maxn];
void doi(int i)
{
    swap(aa[0][i],aa[1][i]);
    swap(aa[0][i],aa[2][i]);
}
void xuly()
{   memset(ca,false,sizeof(ca));
    for (int i=1; i<=n; i++)
        if ( !ca[i] ){
        for (int j=1; j<=n; j++)
            if ( !ca[j] && i!=j){
            if ( aa[0][i]==aa[0][j] ) { ca[i]=true; ca[j]=true;  doi(i); doi(j); continue; }
            if ( aa[1][i]==aa[1][j] && i!=j ) {ca[i]=true;ca[j]=true;continue;}
            if ( aa[0][i]==aa[1][j]  ) { ca[i]=true; ca[j]=true; doi(i); continue; }
            if ( aa[1][i]==aa[0][j] ) { ca[i]=true; ca[j]=true;  doi(j);  continue;}
        }
    }
}
bool cmp(int i,int j)
{
    return aa[0][i] < aa[0][j];
}

int main()
{   freopen("names.inp","r",stdin);
    freopen("names.out","w",stdout);
    cin>>n;
    for (int i=1; i<=n; i++){
        cin>>aa[0][i]>>aa[1][i]>>aa[2][i];
    }
    xuly();
    for (int i=1; i<=n; i++) cs[i]=i;
    sort(cs+1,cs+n+1,cmp);
    for (int i=1; i<=n; i++)
        cout<<aa[0][cs[i]]<<" "<<aa[1][cs[i]]<<" "<<aa[2][cs[i]]<<endl;

}
