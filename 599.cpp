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

map<char, vector<char>> m;
bool vis[128];
int n;

int dfs(char n){
	if(vis[n]) return 0;
	vis[n] = true;
	int num = 1;

	for(auto x: m[n]){
		if(x == '#') break;
		if(!vis[x]){
			num += dfs(x);
		}
	}
	return num;
}

int main() {
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	int tests;
	cin>>tests;
	cin.ignore();
	while(tests-->0){

		m.clear();

		while(1){
			string str;
			getline(cin, str);
			if(str[0] == '*') break;
			m[str[1]].push_back(str[3]);
			m[str[3]].push_back(str[1]);
		}

		string str;
		getline(cin, str);
		REP(i, str.length()) m[str[i++]].push_back('#');
		n = m.size();
		
		clr(vis);

		int trees = 0, acorns = 0;

		for(auto x: m){
			
			if(!vis[x.first]){
				int n = dfs(x.first);
				if(n > 1) trees++;
				else acorns++;
			}
			
		}

		cout<<"There are "<<trees<<" tree(s) and "<<acorns<<" acorn(s).\n";
		
	}
}