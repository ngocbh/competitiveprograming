#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#define DEBUG 0
using namespace std;

int eqvln(string a, string b, int len){
	if(len % 2 == 1){
		if(a == b)
			return 1;
		else
			return 0;
	}
	if(a == b)
		return 1;

	string a1, a2, b1, b2;
	a1 = a.substr(0, len / 2);
	a2 = a.substr(len / 2);
	b1 = b.substr(0, len / 2);
	b2 = b.substr(len / 2);
	if(eqvln(a1, b1, len / 2) && eqvln(a2, b2, len / 2))
		return 1;
	else if(eqvln(a1, b2, len / 2) && eqvln(a2, b1, len / 2))
		return 1;

	return 0;
}

int main(){
	//if(DEBUG)
    //freopen("D.inp", "r", stdin);

	string a, b;
	cin >> a >> b;
	puts(eqvln(a, b, a.length()) ? "YES" : "NO");
	return 0;
}
