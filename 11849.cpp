#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i = a; i < b; i++)
#define RFOR(i,a,b) for(int i = b-1; i >= a; i--)
#define REP(i, n) FOR(i, 0, n)
#define RREP(i, n) RFOR(i, 0, n)
#define si(x) scanf("%d", &x)
#define clr(x) memset(x, 0, sizeof x)

bool flag1 = false, flag2 = false;
int caseNo = 1;

int dirx[] = {1,0,-1,0,1,1,-1,-1};
int diry[] = {0,1,0,-1,1,-1,-1,1};

int main() {
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	while(1){
		int n, m;
		cin>>n>>m;
		if(n == 0 and m == 0) break;

		multiset<int> ja;
		multiset<int> ji;
		
		REP(i, n) {
			int a; cin>>a;
			ja.insert(a);
		}

		REP(i, m){
			int a; cin>>a;
			ji.insert(a);
		}

		int ans = 0;
		for(auto x : ja){
			if(ji.count(x) > 0) ans++;
		}
		cout<<ans<<'\n';
	}
}