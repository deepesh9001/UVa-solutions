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
	int m = board[0].length();
	string str = "";
	REP(i, n) str += "*";
	vector<string> ans(m, str);

	REP(i, n) REP(j, m)
		ans[j][i] = board[i][j];
	
	return ans;
}

int main(){
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	
	int m,n;
	while(scanf("%d%d",&m,&n) == 2){

		vector<string> board(m);
		int num[m][n];
		clr(num);

		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		REP(i, m) getline(cin, board[i]);

		int count = 1;
		REP(j, n) if(board[0][j] != '*') num[0][j] = count++;
		FOR(i, 1, m){
			char last = board[i][0];
			if(last != '*') num[i][0] = count++;
			FOR(j, 1, n) {
				char up = board[i-1][j];
				if(last == '*' and board[i][j] != '*') {
					num[i][j] = count++;
				}
				else if(up == '*' and board[i][j] != '*') num[i][j] = count++;
				last = board[i][j];
			}
			
		}

		cout<<"puzzle #"<<caseNo++<<":\n";
		cout<<"Across\n";
		REP(i, m){
			int start = 0;
			flag2 = false;
			while(!flag2){
				int idx = board[i].find('*', start);
				string str;
				if(idx == -1){ 
					str = board[i].substr(start, n - start);
					flag2 = true;
				}
				else{
					str = board[i].substr(start, idx - start); 
				}
				if(str.length() > 0) cout<<"   "<<num[i][start]<<". "<<str<<'\n';
				start = idx+1;
			}
		}
		cout<<"Down\n";
		
		vector<string> tboard = transpose(board);

		REP(i, n){
			if(board[0][i] != '*'){
				int idx = tboard[i].find('*');
				string str;
				if(idx > -1) str = tboard[i].substr(0,idx);
				else str = tboard[i];
				cout<<"   "<<num[0][i]<<". "<<str<<'\n';
			}
		}
		FOR(i,1,m){
			REP(j, n){
				char last = board[i-1][j];
				if(last == '*' and board[i][j] != '*'){
					int idx = tboard[j].find('*', i);
					string str;
					if(idx > -1) str = tboard[j].substr(i, idx - i);
					else str = tboard[j].substr(i, m - i);
					cout<<"   "<<num[i][j]<<". "<<str<<'\n';
				}
			}
		}

		cout<<'\n';
	}
}