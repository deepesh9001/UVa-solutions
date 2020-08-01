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

	int n, m;
	cin>>n>>m;

	vector<vector<pair<int, int>>> v(n);
	REP(i, n){
		int n0;
		cin>>n0;

		v[i].resize(n0);
		REP(j, n0) cin>>v[i][j].first;
		REP(j, n0) cin>>v[i][j].second;
	}

	vector<pair<int, int>> ans[m+1];
	
	REP(i, n) 
		REP(j, v[i].size())
			ans[v[i][j].first].push_back({i+1, v[i][j].second});
		
		
	

	cout<<m<<' '<<n<<'\n';
	FOR(i, 1, m+1){
		cout<<ans[i].size()<<' ';
		REP(j, ans[i].size()) cout<<ans[i][j].first<<' ';
		cout<<'\n';
		REP(j, ans[i].size()) cout<<ans[i][j].second<<' ';
		cout<<'\n';
		
	}

	
	
}