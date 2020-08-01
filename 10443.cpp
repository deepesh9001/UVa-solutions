#include <bits/stdc++.h>

#define FOR(i,a,b) for(int i = a; i < b; i++)
#define RFOR(i,a,b) for(int i = b-1; i >= a; i--)
#define REP(i, n) FOR(i, 0, n)
#define RREP(i, n) RFOR(i, 0, n)
#define si(x) scanf("%d", &x)
#define clr(x) memset(x, 0, sizeof x)

using namespace std;

bool flag1 = false, flag2 = false;
int caseNo = 1;

int dirx[] = {1,0,-1,0,1,1,-1,-1};
int diry[] = {0,1,0,-1,1,-1,-1,1};

bool check(char ch1, char ch2){
	switch (ch1)
	{
	case 'R':
		switch(ch2){
			case 'P':
				return false;
				break;
			case 'S':
				return true;
				break;	
		}
		break;
	case 'P':
		switch(ch2){
			case 'R':
				return true;
				break;
			case 'S':
				return false;
				break;	
		}
		break;
	case 'S':
		switch(ch2){
			case 'P':
				return true;
				break;
			case 'R':
				return false;
				break;	
		}
		break;
	
	
	default:
		break;
	}

	return true;
}

int main(){
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	
	int n;
	cin>>n;
	while(n-->0){
		int a, b, c;
		cin>>a>>b>>c;
		vector<vector<char>> grid(a, vector<char>(b));
		vector<vector<char>> ans(a, vector<char>(b));
		

		REP(i,a) REP(j,b) cin>>grid[i][j];

		while(c-->0){
			ans = grid;
			REP(i, a) REP(j, b-1){
				bool flag = check(ans[i][j], ans[i][j+1]);
				
				if(flag) grid[i][j+1] = ans[i][j];
				else grid[i][j]= ans[i][j+1];
			}
			REP(i, a-1) REP(j, b) {
				bool flag = check(ans[i][j], ans[i+1][j]);

				if(flag) grid[i+1][j] = ans[i][j];
				else grid[i][j] = ans[i+1][j];
			}

		}
		REP(i, a){
			REP(j, b){
				cout<<grid[i][j];
			}
			cout<<'\n';
		}
		cout<<'\n';
		
	}
	
	
	
}