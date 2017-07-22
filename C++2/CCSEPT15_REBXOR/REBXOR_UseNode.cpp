#include <bits/stdc++.h>
 
const long N = 4 * 100000 + 1;
 
using namespace std;
 
typedef long long LL;
class node_child
{
public:
    node_child *child[2];
    node_child()
    {
        child[1]=child[0]=NULL;
    }
};
 
int n;
int a[N], sum[N], R1[N], L2[N], pow2[33], MAX;
 
node_child *getNode(void)
{
    node_child *pNode = NULL;
 
    pNode = (node_child *)malloc(sizeof(node_child));
 
    if( pNode )
    {
        int i;
 
        for(i = 0; i < 2; i++)
        {
            pNode->child[i] = NULL;
        }
    }
 
    return pNode;
}
 
node_child *pCrawl;
int bb[33] , cc[33], cj , x;
inline void insert_trie(node_child *pTrie,int x)
{
        pCrawl = pTrie;
 
        cj = 30;
                while ( cj >= 0 ) {
                        bb[cj] = x & 1;
                        x = x >> 1;
                        --cj;
                }
 
        for (int i = 0; i <= 30; i++) {
 
                if ( pCrawl->child[bb[i]] == NULL ) {
                        pCrawl->child[bb[i]] = getNode();
                }
 
                pCrawl = pCrawl->child[bb[i]];
        }
}
 
int res;
inline int search_trie(node_child *pTrie,int x )
{
        res = 0;
        pCrawl = pTrie;
 
        cj = 30;
                    while ( cj >= 0 ) {
                        bb[cj] = 1 -  x & 1;
                        x = x >> 1;
                        --cj;
                    }
 
        for (int i = 0; i <= 30; i++)
        {
                if ( pCrawl->child[bb[i]] == NULL )
                        pCrawl = pCrawl->child[1-bb[i]];
                else
                        pCrawl = pCrawl->child[bb[i]], res += pow2[i];
        }
 
        return res;
}
 
int main()
{
        freopen("REBXOR.inp","r",stdin);
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
 
        sum[1] = a[1];
        for (int i = 2; i <= n; i++) sum[i] = sum[i-1] ^ a[i];
 
        pow2[30] = 1;
        for (int i = 29; i >= 1; i-- ) pow2[i] = pow2[i+1] * 2;
 
        ///========= Calc__R1
 
        for (int i = 0; i <= 32; i++) bb[i] = 0;
 
        node_child *trie1 = getNode();
        insert_trie(trie1 , 0);
        int cx = 0;
        map <int,int> m1, m2;
        for (int i = 1; i <= n; i++) {
                cx = sum[i];
                if ( m1[cx] == 0 )
                    insert_trie(trie1 , cx);
                else m1[cx] = 1;
                R1[i] = search_trie(trie1 , cx);
        }
 
        ///======== Calc_L1
        for (int i = 1; i <= n; i++)
                L2[i] = max(L2[i-1] , R1[i]);
 
        ///======== Calc_kq;
        int ans = 0;
        for (int i = 0; i <= 32; i++) bb[i] = 0;
        trie1 = getNode();
 
        for (int i = n; i >= 1; i--)
        {
                    if ( i != n ) {
                            ans = max(ans , L2[i] + search_trie(trie1 , sum[i]) );
                    }
                    if ( m2[sum[i]] == 0 )
                        insert_trie(trie1 , sum[i]);
                    else m2[sum[i]] = 1;
        }
        printf("%d", ans);
 
}
 
