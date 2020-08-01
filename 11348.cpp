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

	int n;
	cin>>n;
	while(n-->0){
		int f;
		cin>>f;

		vector<vector<int>> v(f);
		map<int, int> m;
		
		REP(i, f){
			int t;
			cin>>t;

			v[i].resize(t);

			REP(j, t){
				cin>>v[i][j];
				m[v[i][j]]++;
			}
		}

		int total = 0;
		for(auto x: m) if(x.second == 1) total++;
		

		vector<int> g(f);

		REP(i, f) REP(j, v[i].size())
			if(m[v[i][j]] == 1) g[i]++;
				
		cout<<"Case "<<caseNo++<<": ";
		if(total != 0) REP(i, f) printf("%.6f%% ", g[i]*100./total);
		else REP(i, f) printf("%.6f%% ", 0.);
		cout<<'\n';

	}
}