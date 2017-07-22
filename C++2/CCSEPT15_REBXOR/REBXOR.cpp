#include <bits/stdc++.h>

const long N = 4 * 100000 + 1;

using namespace std;

typedef long long LL;
struct data{
        int bit , child[2];
};
typedef vector < data > _array;
int n;
int a[N], sum[N], R1[N], L2[N], pow2[33], child_init[2];

int cj, bb[33];
void insert_trie(_array &Trie,int x)
{
        cj = 30;
                while ( cj >= 0 ) {
                        bb[cj] = x & 1;
                        x = x >> 1;
                        --cj;
                }
        int pCrawl = 0;
        data t;

        for (int i = 0; i <= 30; i++) {

                if ( Trie[pCrawl].child[bb[i]] == -1 ) {
                        t.bit = bb[i];
                        t.child[0] = -1;
                        t.child[1] = -1;
                        Trie.push_back(t);
                        Trie[pCrawl].child[bb[i]] = Trie.size()-1;
                }

                pCrawl = Trie[pCrawl].child[bb[i]];
        }
}

int res;
int search_trie(_array &Trie,int x )
{
        res = 0;

        cj = 30;
                    while ( cj >= 0 ) {
                        bb[cj] = 1 -  x & 1;
                        x = x >> 1;
                        --cj;
                    }
        data t;
        int pCrawl = 0;
        for (int i = 0; i <= 30; i++)
        {
                if ( Trie[pCrawl].child[bb[i]] == -1 )
                        pCrawl = Trie[pCrawl].child[ 1-bb[i] ];
                else
                        pCrawl = Trie[pCrawl].child[ bb[i] ] , res += pow2[i];
        }

        return res;
}

int main()
{
        //freopen("REBXOR.inp","r",stdin);
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) scanf("%d", &a[i]);

        sum[1] = a[1];
        for (int i = 2; i <= n; i++) sum[i] = sum[i-1] ^ a[i];

        pow2[30] = 1;
        for (int i = 29; i >= 1; i-- ) pow2[i] = pow2[i+1] * 2;

        ///========= Calc__R1

        for (int i = 0; i <= 32; i++) bb[i] = 0;
    
        data t; t.bit = 0; t.child[0] = -1; t.child[1] = -1;

        _array trie1;
        trie1.push_back(t);
        insert_trie(trie1 , 0);

        int cx = 0;

        for (int i = 1; i <= n; i++) {
                cx = sum[i];
                insert_trie(trie1 , cx);
                R1[i] = search_trie(trie1 , cx);
        }

        ///======== Calc_L1

        for (int i = 1; i <= n; i++)
                L2[i] = max(L2[i-1] , R1[i]);

        ///======== Calc_kq;

        int ans = 0;
        _array trie2;
        trie2.push_back(t);

        for (int i = n; i >= 1; i--)
        {
                    if ( i != n ) {
                            ans = max(ans , L2[i] + search_trie(trie2 , sum[i]) );
                    }
                    insert_trie(trie2 , sum[i]);
        }
        printf("%d", ans);

}
