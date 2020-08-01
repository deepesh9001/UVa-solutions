#include <bits/stdc++.h>

#define FOR(i,a,b) for(int i = a; i < b; i++)
#define RFOR(i,a,b) for(int i = b-1; i >= a; i--)
#define REP(i, n) FOR(i, 0, n)
#define RREP(i, n) RFOR(i, 0, n)
#define si(x) scanf("%d", &x)
#define clr(x) memset(x, 0, sizeof x)

using namespace std;

bool flag = false;
int caseNo = 1;

int dirx[] = {1,0,-1,0,1,1,-1,-1};
int diry[] = {0,1,0,-1,1,-1,-1,1};

bool check(vector<vector<char>> p, char ch){
	REP(i, 3){
		if(p[i][0] == p[i][1] and p[i][0] == p[i][2] and p[i][0] == ch) return true;
		if(p[0][i] == p[1][i] and p[0][i] == p[2][i] and p[0][i] == ch) return true;
	}

	if(p[0][0] == p[1][1] and p[2][2] == p[0][0] and p[0][0] == ch) return true;
	if(p[0][2] == p[1][1] and p[1][1] == p[2][0] and p[1][1] == ch) return true;

	return false;
}

int main(){
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);	
	
	int n;
	cin>>n;
	while(n-->0){
		vector<vector<char>> cross(3, vector<char>(3,'.'));

		REP(i, 3) REP(j, 3) cin>>cross[i][j];
		
		int x = 0, o = 0;

		REP(i, 3) REP(j, 3) ((cross[i][j] == 'X') ? x++ : (cross[i][j] == 'O' ? o++ : 0));

		flag = false;
		if(o > x) flag = true;
		else if(x -1 > o) flag = true;
		else if(check(cross, 'X') and check(cross, 'O')) flag = true;
		else if(x > o and check(cross,'O')) flag = true;

		if(flag) cout<<"no\n";
		else cout<<"yes\n";

		cin.ignore();
	}
	
	
}