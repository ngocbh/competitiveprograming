#include <fstream>

using namespace std;
ifstream fi("caro.inp");
ofstream fo("caro.out");
int n,m,dx[2][4][1002],d0[2][4][1002],ic=0,im=1;
bool kt;
string s;
void xuly1(int j)
{
    for (int i=0; i<=3; i++) {
         dx[im][i][j]=0;
         d0[im][i][j]=0;
    }
}
void xuly2(int j)
{
        d0[im][0][j]=d0[im][0][j-1]+1;
        if (d0[im][0][j]==5) {  kt=true; return; }

        d0[im][1][j]=d0[ic][1][j-1]+1;
        if (d0[im][1][j]==5) {  kt=true; return; }

        d0[im][2][j]=d0[ic][2][j]+1;
        if (d0[im][2][j]==5) {  kt=true; return; }

        d0[im][3][j]=d0[ic][3][j+1]+1;
        if (d0[im][3][j]==5) {  kt=true; return; }
        //fo<< d0[im][3][j]<<" "<<j<<endl;
        for (int i=0; i<=3; i++) dx[im][i][j]=0;

}
void xuly3(int j)
{
        dx[im][0][j]=dx[im][0][j-1]+1;
        if (dx[im][0][j]==5) { kt=true;  return; }

        dx[im][1][j]=dx[ic][1][j-1]+1;
        if (dx[im][1][j]==5) { kt=true; return; }

        dx[im][2][j]=dx[ic][2][j]+1;
        if (dx[im][2][j]==5) { kt=true; return; }

        dx[im][3][j]=dx[ic][3][j+1]+1;
        if (dx[im][3][j]==5) { kt=true; return; }

        for (int i=0; i<=3; i++) d0[im][i][j]=0;

}
int main()
{
    fi>>n>>m;
    kt=false;
    for (int i=1; i<=n; i++){
        //if (kt) break;
        fi>>s;
        for (int j=1; j<=m; j++){
            if (kt) break;
            switch (s[j-1]){
               case '.' : { xuly1(j); break;}
               case 'O' : { xuly2(j); break;}
               case 'X' : { xuly3(j); break;}
            }
        }
        im=1-im;
        ic=1-ic;
    }
    if (kt) fo<<"Yes"; else fo<<"No";

}
