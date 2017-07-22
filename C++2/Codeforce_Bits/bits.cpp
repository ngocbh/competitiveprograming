/*C. Bits
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
Let's denote as  the number of bits set ('1' bits) in the binary representation of the non-negative integer x.

You are given multiple queries consisting of pairs of integers l and r. For each query, find the x, such that l ≤ x ≤ r, and is maximum possible. If there are multiple such numbers find the smallest of them.

Input
The first line contains integer n — the number of queries (1 ≤ n ≤ 10000).

Each of the following n lines contain two integers li, ri — the arguments for the corresponding query (0 ≤ li ≤ ri ≤ 1018).

Output
For each query print the answer in a separate line.

Sample test(s)
input
3
1 2
2 4
1 10
output
1
3
7*/
#include <stdio.h>
__int64 l, r;
void solve(){
while((l | (l + 1)) <= r){
 l = (l | (l + 1));
}
printf("%I64d\n",l);
}
int main(){
int n;
scanf("%d",&n);
 while(n --){
  scanf("%I64d %I64d",&l,&r);
  solve();
 }
}
