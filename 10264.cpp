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

bool isPower2(int a){
	a &= ~(a & -a);
	return !a*true + a*false;
}

int main() {
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

    int n;
	while(si(n) == 1){
		vector<int> v(1<<n);

		REP(i, 1<<n) cin>>v[i];

		vector<int> adj[1<<n];
		vector<int> potency(1<<n);
		REP(i, 1<<n) FOR(j, i+1, 1<<n)
			if(isPower2(i^j)){
				adj[i].push_back(j);
				adj[j].push_back(i);
			}

		REP(i, 1<<n) REP(j, adj[i].size()){
			potency[i] += v[adj[i][j]];
		}

		int ans = 0;
		REP(i, 1<<n) REP(j, adj[i].size()){
			if(potency[i] + potency[adj[i][j]] > ans) ans = potency[i] + potency[adj[i][j]];
		}

		cout<<ans<<'\n';

	}
}