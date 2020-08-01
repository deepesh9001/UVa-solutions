#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i = a; i < b; i++)
#define RFOR(i,a,b) for(int i = b-1; i >= a; i--)
#define REP(i, n) FOR(i, 0, n)
#define RREP(i, n) RFOR(i, 0, n)
#define si(x) scanf("%d", &x)
#define clr(x) memset(x, 0, sizeof x)

typedef pair<int, int> pii;
typedef vector<vector<int>> vvi;
typedef vector<int> vi;

bool flag1 = false, flag2 = false;
int caseNo = 1;

int dirx[] = {1,0,-1,0,1,1,-1,-1};
int diry[] = {0,1,0,-1,1,-1,-1,1};
bool vis[1<<16];
vi adj[1<<16];

void dfs(int s, int d){
	if(vis[s]) return;
	vis[s] = true;

	for(auto x: adj[s])
		if(!vis[x])
			dfs(x, d);
}

int main() {
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	int tests;
	cin>>tests;

	cin.ignore();

	while(tests-->0){
		int n; cin>>n;
		REP(i, n+1) adj[i].clear();

		int succ = 0, unsucc = 0;
		cin.ignore();
		while(1){
			string str;
			getline(cin, str);

			if(str.length() == 0) break;

			int ci, cj;
			ci = str[2] - '0', cj = str[4] - '0';

			if(str[0] == 'c') adj[ci].push_back(cj), adj[cj].push_back(ci);
			else{
				REP(i, n+1) vis[i] = false;
				dfs(ci, cj);
				if(vis[cj]) succ++;
				else unsucc++;
			}
		}	

		cout<<succ<<", "<<unsucc<<'\n';
		cout<<'\n';
	}

	
}