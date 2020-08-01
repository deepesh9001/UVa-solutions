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

vector<string> transpose(vector<string> board){
	int n = board.size();
	vector<string> ans(n);

	REP(i, n) REP(j, n)
		ans[j][i] = board[i][j];
	
	return ans;
}

int main(){
	freopen("in.txt", "r", stdin);

	int n; 
	while(cin>>n and n > 0){
		string str = "";
		REP(i, n) str += "0";
		vector<string> board(n, str);
		vector<vector<string>> patterns;
		
		flag2 = false;
		int atpos = 0;
		char player;
		REP(i, 2*n){
			int a, b;
			char c;
			cin>>a>>b>>c;

			if(c == '+') board[a-1][b-1] = '1';
			else board[a-1][b-1] = '0';

			for(auto x : patterns){
				if(x == board){
					flag2 = true;
					atpos = i;
					if(i%2 == 0) player = '2';
					else player = '1';
					break;
				}
			}

			if(flag2) continue;

			patterns.push_back(board);

			vector<string> tboard = transpose(board);
			patterns.push_back(tboard);

			tboard = transpose(tboard);
			patterns.push_back(tboard);
			
			tboard = transpose(tboard);
			patterns.push_back(tboard);
		}
		if(flag2) cout<<"Player "<<player<<" wins on move "<<atpos+1<<'\n';
		else cout<<"Draw\n";

	}
}