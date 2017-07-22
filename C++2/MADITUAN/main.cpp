#include<iostream>
#include<fstream>
using namespace std;
int n,x,y,dd[10000][10000],kn[10000][10000],vt[3][10000],di[3][9];
bool ngung=false;
ofstream f1("MA.OUT",ios::out);
int ktkn(int i,int j){
    int dem=0;
    for(int l=1;l<=8;l++)
        if(i+di[1][l]>=1 && i+di[1][l]<=n && j+di[2][l]>=1 && j+di[2][l]<=n) dem++;
    return dem;
}
void doc_file(){
    ifstream f("MA.INP",ios::in);
    f>>n;// Kich thuoc ban co
    f>>x>>y;//Toa do ban dau xuat phat
    f.close();
    //khoi tao
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++) dd[i][j]=0;
    di[1][1]=-1; di[2][1]=-2;
    di[1][2]=1; di[2][2]=-2;
    di[1][3]=-1; di[2][3]=2;
    di[1][4]=1; di[2][4]=2;
    di[1][5]=-2; di[2][5]=-1;
    di[1][6]=-2; di[2][6]=1;
    di[1][7]=2; di[2][7]=-1;
    di[1][8]=2; di[2][8]=1;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++) kn[i][j]=ktkn(i,j);
}

int kiemtra(){
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++) if(dd[i][j]==0) return 0;
    return 1;
}
void in(){
    cout<<endl;
    for(int i=1;i<=n;i++){
        cout<<endl;
        for(int j=1;j<=n;j++) cout<<kn[i][j]<<" ";
    }
    getch();
}

void xuly(int _i,int _x,int _y){

if(_i==n*n&&ngung==false){
    ngung=true;
    if(kiemtra()==1){
        cout<<endl;
        for(int j=1;j<=_i-1;j++){
            cout<<endl<<vt[1][j]<<" "<<vt[2][j];
        }
    }
}
else if(ngung==false){
    int _di[3][9],dem=0,i,j,l;
    //tim cac duong di tiep
    for( l=1;l<=8;l++)
        if(_x+di[1][l]>=1 && _x+di[1][l]<=n && _y+di[2][l]>=1 && _y+di[2][l]<=n &&dd[_x+di[1][l]][_y+di[2][l]]==0){
            dem++;
            _di[0][dem]=kn[_x+di[1][l]][_y+di[2][l]];
            _di[1][dem]=_x+di[1][l];
            _di[2][dem]=_y+di[2][l];
        }
    //sap xep theo kha nang
    int temp[3];
    for( i=2;i<=dem;i++)
        for( j=dem;j>=i;j--)
        if(_di[0][j]<_di[0][j-1]){
                temp[0]=_di[0][j];temp[1]=_di[1][j];temp[2]=_di[2][j];
                _di[0][j]=_di[0][j-1];_di[1][j]=_di[1][j-1];_di[2][j]=_di[2][j-1];
                _di[0][j-1]=temp[0];_di[1][j-1]=temp[1];_di[2][j-1]=temp[2];
        }
    //Giam kha nang
    for(i=1;i<=dem;i++)
        kn[_di[1][i]][_di[2][i]]--;
    kn[_x][_y]--;
    //bat dau duyet
    for(i=1;i<=dem;i++){
        //danh dau
        dd[_di[1][i]][_di[2][i]]=1;
        //vi tri tiep theo
        vt[1][_i]=_di[1][i];
        vt[2][_i]=_di[2][i];
        //goi xu ly cho vi tri tiep theo
        xuly(_i+1,_di[1][i],_di[2][i]);
        //bo danh dau
        dd[_di[1][i]][_di[2][i]]=0;
    }
    //Tang lai kha nang
    for(i=1;i<=dem;i++)
        kn[_di[1][i]][_di[2][i]]++;
    kn[_x][_y]++;
}
}

int main(){
    doc_file();
    dd[x][y]=1;
    xuly(1,x,y);
    if(ngung) cout<<"\nKet thuc.";
    else cout<<"\nKhong co duong di";
    getch();
    return 0;
}
