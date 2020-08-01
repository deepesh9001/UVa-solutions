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

vector<vector<char>> f(vector<vector<char>> g){
	vector<vector<char>> ans(3, vector<char>(3));
	REP(i, 3) REP(j, 3) g[i][j] -= '0';
	REP(i, 3) REP(j, 3) REP(k, 4) 
		if(i + dirx[k] >= 0 and j + diry[k] >= 0 and i + dirx[k] < 3 and j + diry[k] < 3){
			ans[i][j] += g[i + dirx[k]][j + diry[k]];
			ans[i][j] %= 2;
	}
	REP(i, 3) REP(j, 3) ans[i][j] += '0';
	return ans;
}

int main() {
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

    int n;
	cin>>n;

	while(n-->0){
		cin.ignore();

		vector<vector<char>> g(3, vector<char>(3));

		REP(i, 3) REP(j, 3) cin>>g[i][j];

		REP(i, 1000){
			vector<vector<char>> fg = f(g);
			if(fg == g){
				if(i == 0){
					cout<<-1<<'\n';
					break;
				}
				cout<<i-1<<'\n';
				break;
			}
			g = fg;
		}

	}
}