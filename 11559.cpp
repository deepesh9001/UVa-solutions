#include <bits/stdc++.h>

#define FOR(i,a,b) for(int i = a; i < b; i++)
#define REP(i, n) FOR(i, 0, n)
#define si(x) scanf("%d", &x)

using namespace std;

int main(){
	freopen("in.txt", "r", stdin);

	int n,b,h,w;
	while(scanf("%d%d%d%d", &n,&b,&h,&w) == 4){
		int min = 1e9;
		REP(i,h){
			int p;
			si(p);
			REP(j,w){
				int a;
				si(a);

				if(a >= n and n*p < min and n*p <= b){
					min = n*p;
				}
			}
		}
		if(min == 1e9) cout<<"stay home\n";
		else cout<<min<<'\n';
	}
}