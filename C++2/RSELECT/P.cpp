#include<bits/stdc++.h>
using namespace std;
#define N 3001
#define M N+1
bool pr[M];
vector <int> prime;
int d[M] ,fr[M] , n , x[M] , a[M] ,demm = 0 , c[M][M];

void snt(){
    memset(pr , true ,sizeof pr);
    pr[1] = false;
    for (int i = 2 ; i <= (int)sqrt(N) ; ++i) if(pr[i]) {
        int j = i * i;
        while (j <= N){
            pr[j] = false;
            j = j + i;
        }
    }
    for (int i = 2; i <= N ; ++i) if (pr[i]) prime.push_back(i);
    for (int i = 2; i <= N ; ++i) {
        int ii = i , dem = 0;
        for (int j = 0 ; j < prime.size() ; ++ j){
         while ( ii % prime[j] == 0) {++dem; ii /= prime[j];}
         a[i] = dem;
         if ( ii == 1 || ii == 0) break;
        }
    }
}

void read(){
    snt();
    memset(fr , 0 ,sizeof fr);
    //-for (int i = 1; i <= N ; ++i) fr[i] = 0;
    //freopen("P.inp" , "r" ,stdin);
    //freopen("P.out" , "w" ,stdout);
    scanf("%d" , &n);
    for (int i = 1; i <= n ;++i) {scanf("%d", &x[i]); ++fr[x[i]]; }
    }

int UCLN(int a , int b) {
    int temp ;
    while (b){
        temp = a % b;
        a = b;
        b = temp;
    }
    return a;
}

void init2(){
    memset(c , 0 ,sizeof c);
    for (int i = 1; i <= N ;++i)
        for (int j = i + 1; j <= N ;++j)
        {
            int uc = (pr[i] && pr[j]) ? 1 : UCLN(i , j); //cout << uc << endl;
            c[i][j] = fr[i] * (a[i] + a[j] - 2 * a[uc]);
            c[j][i] = fr[j] * (a[i] + a[j] - 2 * a[uc]);
        }
}

void thuchien(){
    int sum , res1 = 1000000000,res2 ;
    for (int i = 1; i <= N ;++i){
        sum = 0;
        for (int j = 1; j <= N ;++j) if (i != j) {sum += c[j][i]; /*if (c[j][i] >0) cout << j << " " <<c[j][i] << endl;*/}
        if (sum < res1) {res1 = sum;res2 = i;}
    }
    cout << res1 << " " << res2;
}

int main(){
    read();
    init2();
    thuchien();
    return 0;
}
