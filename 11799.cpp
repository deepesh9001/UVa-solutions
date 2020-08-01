#include <bits/stdc++.h>

#define FOR(i,a,b) for(int i = a; i < b; i++)
#define REP(i, n) FOR(i, 0, n)
#define si(x) scanf("%d", &x)

using namespace std;

int main(){
	freopen("in.txt", "r", stdin);
	int t;
	si(t);

	REP(i, t){
		int n;
		si(n);

		int max = -1;
		REP(j, n) {
			int a; 
			si(a);
			if(a > max) max = a;
		}
		printf("Case %d: %d\n", i+1, max);
	}
}