#include <bits/stdc++.h>

const long N = 100000 + 10;
const long Base = 1000000000 + 7;
using namespace std;

int n, q;
long long a[N] , f[8*N], t1[8*N], t2[8*N], t3[8*N], t4[8*N];
long long ans;
void update_1(int k,int l,int r,int u,int v,int c)
{
    if ( t2[k] != 1 ) {
            f[k] = ( f[k]*t2[k] ) % Base;
            t2[2*k] = ( t2[2*k] * t2[k] ) % Base;
            t2[2*k+1] = ( t2[2*k+1] * t2[k] ) % Base;
            t2[k] = 1;
    }
    t1[k] = ( ( t1[k] + t4[k] )*t2[k] ) % Base;
    t4[k] = 0;
    if ( t1[k] != 0 ) {
            f[k] = ( f[k] + ( (r - l + 1) * t1[k] ) % Base ) % Base;
            t1[2*k] = ( t1[2*k] + t1[k] ) % Base;
            t1[2*k+1] = ( t1[2*k+1] + t1[k] ) % Base;
            t1[k] = 0;
    }
    if ( t3[k] > 0 ) {
            f[k] = (r - l + 1) * t3[k] % Base;
            t3[2*k] = t3[k];
            t3[2*k+1] = t3[k];
            t3[k] = -1;
    }
            if ( u > r || v < l ) return;
            if ( u <= l && v >= r ) {
                    t4[k] = ( t4[k] + c ) % Base;
                    if ( t2[k] != 1 ) {
                            f[k] = ( f[k]*t2[k] ) % Base;
                            t2[2*k] = ( t2[2*k] * t2[k] ) % Base;
                            t2[2*k+1] = ( t2[2*k+1] * t2[k] ) % Base;
                            t2[k] = 1;
                    }
                    t1[k] = ( ( t1[k] + t4[k] )*t2[k] ) % Base;
                    t4[k] = 0;
                    if ( t1[k] != 0 ) {
                            f[k] = ( f[k] + ( (r - l + 1) * t1[k] ) % Base ) % Base;
                            t1[2*k] = ( t1[2*k] + t1[k] ) % Base;
                            t1[2*k+1] = ( t1[2*k+1] + t1[k] ) % Base;
                            t1[k] = 0;
                    }
                    if ( t3[k] > 0 ) {
                            f[k] = (r - l + 1) * t3[k] % Base;
                            t3[2*k] = t3[k];
                            t3[2*k+1] = t3[k];
                            t3[k] = -1;
                    }
                    return;
            }
            int mid;
            mid = (l+r) / 2;
            update_1(2*k,l,mid,u,v,c);
            update_1(2*k+1,mid+1,r,u,v,c);
            f[k] = (f[2*k] + f[2*k+1]) % Base;

}

void update_2(int k,int l,int r,int u,int v,int c)
{
    if ( t2[k] != 1 ) {
            f[k] = ( f[k]*t2[k] ) % Base;
            t2[2*k] = ( t2[2*k] * t2[k] ) % Base;
            t2[2*k+1] = ( t2[2*k+1] * t2[k] ) % Base;
            t2[k] = 1;
    }
    t1[k] = ( ( t1[k] + t4[k] )*t2[k] ) % Base;
    t4[k] = 0;
    if ( t1[k] != 0 ) {
            f[k] = ( f[k] + ( (r - l + 1) * t1[k] ) % Base ) % Base;
            t1[2*k] = ( t1[2*k] + t1[k] ) % Base;
            t1[2*k+1] = ( t1[2*k+1] + t1[k] ) % Base;
            t1[k] = 0;
    }
    if ( t3[k] > 0 ) {
            f[k] = (r - l + 1) * t3[k] % Base;
            t3[2*k] = t3[k];
            t3[2*k+1] = t3[k];
            t3[k] = -1;
    }
            if ( u > r || v < l ) return;
            if ( u <= l && v >= r ) {
                    t2[k] = ( t2[k] * c ) % Base;
                    t4[k] = 0;
                    if ( t2[k] != 1 ) {
                            f[k] = ( f[k]*t2[k] ) % Base;
                            t1[k] = ( ( t1[k] + t4[k] )*t2[k] ) % Base;
                            t4[k] = 0;
                            t2[2*k] = ( t2[2*k] * t2[k] ) % Base;
                            t2[2*k+1] = ( t2[2*k+1] * t2[k] ) % Base;
                            t2[k] = 1;
                    }
                    if ( t1[k] != 0 ) {
                            f[k] = ( f[k] + ( (r - l + 1) * t1[k] ) % Base ) % Base;
                            t1[2*k] = ( t1[2*k] + t1[k] ) % Base;
                            t1[2*k+1] = ( t1[2*k+1] + t1[k] ) % Base;
                            t1[k] = 0;
                    }
                    if ( t3[k] > 0 ) {
                            f[k] = (r - l + 1) * t3[k] % Base;
                            t3[2*k] = t3[k];
                            t3[2*k+1] = t3[k];
                            t3[k] = -1;
                    }
                    return;
            }
            int mid;
            mid = (l+r) / 2;
            update_2(2*k,l,mid,u,v,c);
            update_2(2*k+1,mid+1,r,u,v,c);
            f[k] = (f[2*k] + f[2*k+1]) % Base;

}

void update_3(int k,int l,int r,int u,int v,int c)
{
    if ( t2[k] != 1 ) {
            f[k] = ( f[k]*t2[k] ) % Base;
            t2[2*k] = ( t2[2*k] * t2[k] ) % Base;
            t2[2*k+1] = ( t2[2*k+1] * t2[k] ) % Base;
            t2[k] = 1;
    }
    t1[k] = ( ( t1[k] + t4[k] )*t2[k] ) % Base;
    t4[k] = 0;
    if ( t1[k] != 0 ) {
            f[k] = ( f[k] + ( (r - l + 1) * t1[k] ) % Base ) % Base;
            t1[2*k] = ( t1[2*k] + t1[k] ) % Base;
            t1[2*k+1] = ( t1[2*k+1] + t1[k] ) % Base;
            t1[k] = 0;
    }
    if ( t3[k] > 0 ) {
            f[k] = (r - l + 1) * t3[k] % Base;
            t3[2*k] = t3[k];
            t3[2*k+1] = t3[k];
            t3[k] = -1;
    }
            if ( u > r || v < l ) return;
            if ( u <= l && v >= r ) {
                    t3[k] = c;
                    if ( t2[k] != 1 ) {
                            f[k] = ( f[k]*t2[k] ) % Base;
                            t2[2*k] = ( t2[2*k] * t2[k] ) % Base;
                            t2[2*k+1] = ( t2[2*k+1] * t2[k] ) % Base;
                            t2[k] = 1;
                    }
                    t1[k] = ( ( t1[k] + t4[k] )*t2[k] ) % Base;
                    t4[k] = 0;
                    if ( t1[k] != 0 ) {
                            f[k] = ( f[k] + ( (r - l + 1) * t1[k] ) % Base ) % Base;
                            t1[2*k] = ( t1[2*k] + t1[k] ) % Base;
                            t1[2*k+1] = ( t1[2*k+1] + t1[k] ) % Base;
                            t1[k] = 0;
                    }
                    if ( t3[k] > 0 ) {
                            f[k] = (r - l + 1) * t3[k] % Base;
                            t3[2*k] = t3[k];
                            t3[2*k+1] = t3[k];
                            t3[k] = -1;
                    }
                    return;
            }
            int mid;
            mid = (l+r) / 2;
            update_3(2*k,l,mid,u,v,c);
            update_3(2*k+1,mid+1,r,u,v,c);
            f[k] = (f[2*k] + f[2*k+1]) % Base;

}

void visit(int k,int l,int r,int u,int v)
{
    if ( t2[k] != 1 ) {
            f[k] = ( f[k]*t2[k] ) % Base;
            t2[2*k] = ( t2[2*k] * t2[k] ) % Base;
            t2[2*k+1] = ( t2[2*k+1] * t2[k] ) % Base;
            t2[k] = 1;
    }
    t1[k] = ( ( t1[k] + t4[k] )*t2[k] ) % Base;
    t4[k] = 0;
    if ( t1[k] != 0 ) {
            f[k] = ( f[k] + ( (r - l + 1) * t1[k] ) % Base ) % Base;
            t1[2*k] = ( t1[2*k] + t1[k] ) % Base;
            t1[2*k+1] = ( t1[2*k+1] + t1[k] ) % Base;
            t1[k] = 0;
    }
    if ( t3[k] > 0 ) {
            f[k] = (r - l + 1) * t3[k] % Base;
            t3[2*k] = t3[k];
            t3[2*k+1] = t3[k];
            t3[k] = -1;
    }
            if ( u > r || v < l ) return;
            if ( u <= l && v >= r ) {
                    ans = ( ans + f[k] ) % Base;
                    return;
            }
            int mid;
            mid = (l+r) / 2;
            visit(2*k,l,mid,u,v);
            visit(2*k+1,mid+1,r,u,v);
            f[k] = (f[2*k] + f[2*k+1]) % Base;

}

int main()
{       freopen("ADDMUL.inp","r",stdin);
        scanf("%d %d" , &n, &q);
        for (int i = 1; i <= 8*n; i++)  {
                t3[i] = -1;
                t2[i] = 1;
                t1[i] = 0;
        }
        for (int i = 1; i <= n; i++){
                scanf("%d", &a[i]);
                update_1(1,1,n,i,i,a[i]);
        }
        long l, u, v, c;
        for (int i = 1; i <= q; i++){
                scanf("%d", &l);
                for (int j = 1; j <= 7; j++ ) cout<<f[j]<<" "; cout<<endl;
                for (int j = 1; j <= 7; j++ ) cout<<t2[j]<<" "; cout<<endl;
                for (int j = 1; j <= 7; j++ ) cout<<t1[j]<<" "; cout<<endl;
                for (int j = 1; j <= 7; j++ ) cout<<t4[j]<<" "; cout<<endl;
                cout<<"***"<<endl;
                if ( l < 4 ) {
                        scanf("%d %d %d", &u, &v, &c);
                        if ( l == 1 ) update_1(1,1,n,u,v,c);
                        if ( l == 2 ) update_2(1,1,n,u,v,c);
                        if ( l == 3 ) update_3(1,1,n,u,v,c);
                        continue;
                }       ans = 0;
                        scanf("%d %d", &u, &v);
                        visit(1,1,n,u,v);
                        printf ("%lld\n", ans);
        }

}
